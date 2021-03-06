//
//  UIColor+Judo.m
//  JudoKitObjC
//
//  Copyright (c) 2016 Alternative Payments Ltd
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#import "UIColor+Judo.h"

@implementation UIColor (Judo)

- (UIColor *)inverseColor {
    CGFloat r;
    CGFloat g;
    CGFloat b;
    CGFloat a;
    [self getRed:&r green:&g blue:&b alpha:&a];
    return [UIColor colorWithRed:1 - r green:1 - g blue:1 - b alpha:a];
}

- (CGFloat)greyScale {
    CGFloat r;
    CGFloat g;
    CGFloat b;
    CGFloat a;
    [self getRed:&r green:&g blue:&b alpha:&a];
    return (0.299 * r + 0.587 * g + 0.114 * b);
}

- (BOOL)colorMode {
    return self.greyScale < 0.5;
}

@end
