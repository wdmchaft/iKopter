// ///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2011, Frank Blumenberg
//
// See License.txt for complete licensing and attribution information.
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// ///////////////////////////////////////////////////////////////////////////////

#import <IBAForms/IBAForms.h>
#import "WPGenBaseDataSource.h"
#import "StringToNumberTransformer.h"
#import "SettingsFieldStyle.h"

@interface WPGenBaseDataSource ()
@end

@implementation WPGenBaseDataSource

@synthesize delegate;

- (id)initWithModel:(id)aModel {
  if ((self = [super initWithModel:aModel])) {

  }
  return self;
}

- (void)addAttributeSection{

  IBATextFormField *numberField;

  ////////////////////////////////////////////////////////////////////////////////////////////////////

  IBAFormSection *attributeSection = [self addSectionWithHeaderTitle:nil footerTitle:nil];
  attributeSection.formFieldStyle = [[[SettingsFieldStyle alloc] init] autorelease];
  //------------------------------------------------------------------------------------------------------------------------
  numberField = [[IBATextFormField alloc] initWithKeyPath:@"altitude"
                                                    title:NSLocalizedString(@"Altitude", @"WP Altitude title")
                                         valueTransformer:[StringToNumberTransformer instance]];

  [attributeSection addFormField:[numberField autorelease]];
  numberField.textFormFieldCell.textField.keyboardType = UIKeyboardTypeNumberPad;
  //------------------------------------------------------------------------------------------------------------------------
  numberField = [[IBATextFormField alloc] initWithKeyPath:@"heading"
                                                    title:NSLocalizedString(@"Heading", @"WP Heading title")
                                         valueTransformer:[StringToNumberTransformer instance]];

  [attributeSection addFormField:[numberField autorelease]];
  numberField.textFormFieldCell.textField.keyboardType = UIKeyboardTypeNumbersAndPunctuation;
  //------------------------------------------------------------------------------------------------------------------------
  numberField = [[IBATextFormField alloc] initWithKeyPath:@"toleranceRadius"
                                                    title:NSLocalizedString(@"Radius", @"WP toleranceRadius title")
                                         valueTransformer:[StringToNumberTransformer instance]];

  [attributeSection addFormField:[numberField autorelease]];
  numberField.textFormFieldCell.textField.keyboardType = UIKeyboardTypeNumberPad;
  //------------------------------------------------------------------------------------------------------------------------
  numberField = [[IBATextFormField alloc] initWithKeyPath:@"holdTime"
                                                    title:NSLocalizedString(@"HaltTime", @"WP holdTime title")
                                         valueTransformer:[StringToNumberTransformer instance]];

  [attributeSection addFormField:[numberField autorelease]];
  numberField.textFormFieldCell.textField.keyboardType = UIKeyboardTypeNumberPad;
  //------------------------------------------------------------------------------------------------------------------------
  numberField = [[IBATextFormField alloc] initWithKeyPath:@"wpEventChannelValue"
                                                    title:NSLocalizedString(@"Event", @"WP event title")
                                         valueTransformer:[StringToNumberTransformer instance]];

  [attributeSection addFormField:[numberField autorelease]];
  numberField.textFormFieldCell.textField.keyboardType = UIKeyboardTypeNumberPad;
  //------------------------------------------------------------------------------------------------------------------------
  numberField = [[IBATextFormField alloc] initWithKeyPath:@"altitudeRate"
                                                    title:NSLocalizedString(@"Climb rate", @"WP event title")
                                         valueTransformer:[StringToNumberTransformer instance]];

  [attributeSection addFormField:[numberField autorelease]];
  numberField.textFormFieldCell.textField.keyboardType = UIKeyboardTypeNumberPad;
  //------------------------------------------------------------------------------------------------------------------------
  numberField = [[IBATextFormField alloc] initWithKeyPath:@"speed"
                                                    title:NSLocalizedString(@"Speed", @"WP event title")
                                         valueTransformer:[StringToNumberTransformer instance]];

  [attributeSection addFormField:[numberField autorelease]];
  numberField.textFormFieldCell.textField.keyboardType = UIKeyboardTypeNumberPad;
  //------------------------------------------------------------------------------------------------------------------------
  numberField = [[IBATextFormField alloc] initWithKeyPath:@"camAngle"
                                                    title:NSLocalizedString(@"Camera nick angle", @"WP event title")
                                         valueTransformer:[StringToNumberTransformer instance]];

  [attributeSection addFormField:[numberField autorelease]];
  numberField.textFormFieldCell.textField.keyboardType = UIKeyboardTypeNumberPad;
  //------------------------------------------------------------------------------------------------------------------------
  [attributeSection addFormField:[[[IBABooleanFormField alloc] initWithKeyPath:@"cameraNickControl"
                                                                         title:NSLocalizedString(@"Camera nick control", @"cameraNickControl title")] autorelease]];

}

- (void)setModelValue:(id)value forKeyPath:(NSString *)keyPath {
  [super setModelValue:value forKeyPath:keyPath];

  [self.delegate dataSource:self];
  NSLog(@"%@", [self.model description]);
}

@end