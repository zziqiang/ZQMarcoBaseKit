//
//  ZQMacroSupportTools.h
//  Client
//
//  Created by apple on 2019/12/20.
//  Copyright © 2019 apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZQMacroSupportTools : NSObject

/// 16进制颜色转换
+ (UIColor *)colorWithHexString:(NSString *)color;

/// 判断刘海屏，返回YES表示是刘海屏
+ (BOOL)isNotchScreen;

/// 判断是否包含中文  每一个字符的UTF8格式的长度是否等于3
/// @param url 链接
+ (BOOL)isContainChinese:(NSString *)url;

@end

NS_ASSUME_NONNULL_END
