//
//  ZQMacroColorFontHeader.h
//  Client
//
//  Created by apple on 2019/12/20.
//  Copyright © 2019 apple. All rights reserved.
//

#ifndef ZQMacroColorFontHeader_h
#define ZQMacroColorFontHeader_h
#import "ZQMacroSupportTools.h"

// 颜色
#pragma mark - 颜色

/// RGB颜色
#define kRGBColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
/// RGBA颜色
#define kRGBAColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:(a)]
/// Random颜色
#define kRandomColor  [UIColor colorWithRed:(arc4random_uniform(256))/255.0 green:arc4random_uniform(256)/255.0 blue:(arc4random_uniform(256))/255.0 alpha:1.0]

/// 16进制 颜色 转换 传入 #5D9EE1，5D9EE1，0x5D9EE1 等等
#define kHexColor(_hex_)   [ZQMacroSupportTools colorWithHexString:((__bridge NSString *)CFSTR(#_hex_))]


//kColor
#pragma mark - 固定颜色

#define kWhiteColor             [UIColor whiteColor]

#define kBlackDefaultColor      [UIColor blackColor]
#define kBlack333Color          [UIColor colorWithRed:0.2 green:0.2 blue:0.2 alpha:1.0]
#define kGray666Color           [UIColor colorWithRed:0.4 green:0.4 blue:0.4 alpha:1.0]
#define kGray999Color           [UIColor colorWithRed:0.6 green:0.6 blue:0.6 alpha:1.0]

#define kGrayF5Color            [UIColor colorWithRed:0.96 green:0.96 blue:0.96 alpha:1]

#define kTaobaoPriceColor       [UIColor colorWithRed:1 green:0.33 blue:0 alpha:1]
#define kAlipayBlueColor        [UIColor colorWithRed:0.06 green:0.68 blue:1 alpha:1]
#define kWechatGreenColor       [UIColor colorWithRed:0.03 green:0.76 blue:0.38 alpha:1]


//kFont
#pragma mark - 固定字体

#define kFont(kNum)      [UIFont systemFontOfSize:kNum]
#define kFontBold(kNum)  [UIFont boldSystemFontOfSize:kNum]

#endif /* ZQMacroColorFontHeader_h */
