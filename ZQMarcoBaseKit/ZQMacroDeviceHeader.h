//
//  ZQMacroDeviceHeader.h
//  Client
//
//  Created by apple on 2019/12/20.
//  Copyright © 2019 apple. All rights reserved.
//

#ifndef ZQMacroDeviceHeader_h
#define ZQMacroDeviceHeader_h
#import "ZQMacroSupportTools.h"

#pragma mark - 判断系统版本 应用版本

#define kSystemVersion  [[UIDevice currentDevice].systemVersion doubleValue]
#define kAppVersionCode ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"])


#define kiOS9Later  (kSystemVersion >= 9)
#define kiOS10Later (kSystemVersion >= 10)
#define kiOS11Later (kSystemVersion >= 11)
#define kiOS12Later (kSystemVersion >= 12)
#define kiOS13Later (kSystemVersion >= 13)

// iPhone 手机型号
#pragma mark - iPhone 手机型号

// 判断是否是 ipad
#define kIsPad ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)

// 判断 iPhone6系列 kIsiPhone_6_6s_7_8
#define kIsiPhone_6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)

// 判断iphone6P系列 kiIsPhone_6p_6sp_7p_8p
#define kIsiPhone_6P ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)

// 判断iPhoneX XS
#define kIsPhone_X ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)

// 判断iPhoneXr
#define kIsiPhone_XR ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1624), [[UIScreen mainScreen] currentMode].size) : NO)

// 判断iPhone XSMax
#define kIsiPhone_XSMAX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size) : NO)

/// 是否是iPhonex系列手机
#define kIsiPhoneXSeries (([FMMacroKitTools fm_isNotchScreen]) ? YES : NO)

#endif /* ZQMacroDeviceHeader_h */
