//
// Copyright 2010 Itty Bitty Apps Pty Ltd
// 
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this 
// file except in compliance with the License. You may obtain a copy of the License at 
// 
// http://www.apache.org/licenses/LICENSE-2.0 
// 
// Unless required by applicable law or agreed to in writing, software distributed under
// the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF 
// ANY KIND, either express or implied. See the License for the specific language governing
// permissions and limitations under the License.
//

#import "IBATextFormField.h"
#import "IBAFormConstants.h"
#import "IBAInputCommon.h"
#import "IBAInputManager.h"
#import "IBAInputManager.h"

@implementation IBATextFormField

@synthesize textFormFieldCell = textFormFieldCell_;

- (void)dealloc {
	IBA_RELEASE_SAFELY(textFormFieldCell_);
	
	[super dealloc];
}

- (void)clear:(id)sender {
	[self setFormFieldValue:nil];
}

#pragma mark -
#pragma mark Cell management

- (IBAFormFieldCell *)cell {
	return [self textFormFieldCell];
}

-(BOOL)checkField
{
    return [textFormFieldCell_ checkField];
}

- (IBATextFormFieldCell *)textFormFieldCell {
	if (textFormFieldCell_ == nil) {
		textFormFieldCell_ = [[IBATextFormFieldCell alloc] initWithFormFieldStyle:self.formFieldStyle reuseIdentifier:@"Cell" validator:self.validator];
        textFormFieldCell_.nullable = self.nullable;
        [textFormFieldCell_.clearButton addTarget:self action:@selector(clear:) forControlEvents:UIControlEventTouchUpInside];
		textFormFieldCell_.textField.delegate = self;
		textFormFieldCell_.textField.enabled = NO;
	}
	
	return textFormFieldCell_;
}

- (void)updateCellContents {
	self.textFormFieldCell.label.text = self.title;
	self.textFormFieldCell.textField.text = [self formFieldStringValue];
}


#pragma mark -
#pragma mark UITextFieldDelegate

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
	return [[IBAInputManager sharedIBAInputManager] activateNextInputRequestor];;
}

- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string { 
    NSLog(@"S:%@",string);
    
    if (textField.keyboardType==UIKeyboardTypeNumbersAndPunctuation ||
        textField.keyboardType==UIKeyboardTypeDecimalPad || 
        textField.keyboardType==UIKeyboardTypeNumberPad ) {
        
        NSNumberFormatter *numberFormatter = [[[NSNumberFormatter alloc] init]autorelease];
        [numberFormatter setNumberStyle:NSNumberFormatterDecimalStyle];
        
        if (textField.keyboardType==UIKeyboardTypeNumberPad) {
            numberFormatter.maximumFractionDigits=0;
        }
        
        NSNumber* candidateNumber=[NSNumber numberWithInt:0];
        NSString* candidateString = [textField.text stringByReplacingCharactersInRange:range withString:string];
        NSError* error=nil;
        range = NSMakeRange(0, [candidateString length]);
        
        [numberFormatter getObjectValue:&candidateNumber forString:candidateString range:&range error:&error];
        
        if (([candidateString length] > 0) && (candidateNumber == nil || range.length < [candidateString length])) {
            return NO;
        }
        else {
            return YES;
        }
    }
    
    return YES;
}


#pragma mark -
#pragma mark IBAInputRequestor

- (NSString *)dataType {
	return IBAInputDataTypeText;
}

- (void)activate {
	self.textFormFieldCell.textField.enabled = YES;
	[super activate];
}

- (BOOL)deactivate {
	BOOL deactivated = [self setFormFieldValue:self.textFormFieldCell.textField.text];
	if (deactivated) {
		self.textFormFieldCell.textField.enabled = NO;
		deactivated = [super deactivate];
	}
	
	return deactivated;
}

- (UIResponder *)responder {
	return self.textFormFieldCell.textField;
}

@end
