//
//  ZQMacroViewHeader.h
//  Client
//
//  Created by apple on 2019/12/20.
//  Copyright © 2019 apple. All rights reserved.
//

#ifndef ZQMacroViewHeader_h
#define ZQMacroViewHeader_h
#import "ZQMacroSupportTools.h"

#pragma mark -  屏幕适配

#define kFit_6W(x)       ([UIScreen mainScreen].bounds.size.width * ((x)/375.0))
#define kFit_6H(x)       ([UIScreen mainScreen].bounds.size.height * ((x)/667.0))


#pragma mark -  状态栏 导航栏 tabbar高度
/*状态栏高度*/
#define kStatusBarHeight (([ZQMacroSupportTools isNotchScreen]) ? 44.0 : 20.0)
/*状态栏和导航栏总高度*/
#define kNavBarAllH ((([ZQMacroSupportTools isNotchScreen]) ? 88.0 : 64.0) + kStatusBarHeight)
/*导航栏总高度*/
#define kNavBarH (([ZQMacroSupportTools isNotchScreen]) ? 88.0 : 64.0)
/*TabBar高度*/
#define kTabbarH (([ZQMacroSupportTools isNotchScreen]) ? 83.0 : 49.0)
/*顶部安全区域远离高度*/
#define kSafeHeightTopBar (CGFloat)(([ZQMacroSupportTools isNotchScreen])?(44.0):(0))
/*底部安全区域远离高度*/
#define kSafeHeightBottom (CGFloat)(([ZQMacroSupportTools isNotchScreen])?(34.0):(0))


#pragma mark - 圆角和加边框

#define kViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]];

// View 圆角
#define kViewRadius(View, Radius)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];

// View 部分圆角
#define kViewSomeRadius(View, kRadius, isBottomLeft, isBottomRight, isTopLeft, isTopRight) \
\
UIRectCorner corner;\
if (isBottomLeft) corner = UIRectCornerBottomLeft;\
if (isBottomRight) corner = corner | UIRectCornerBottomRight;\
if (isTopLeft) corner = corner | UIRectCornerTopLeft;\
if (isTopRight) corner = corner | UIRectCornerTopRight;\
UIBezierPath *maskPath = [UIBezierPath bezierPathWithRoundedRect:View.bounds   byRoundingCorners:corner  cornerRadii:CGSizeMake(kRadius, kRadius)]; \
CAShapeLayer *maskLayer = [[CAShapeLayer alloc] init]; \
maskLayer.frame = View.bounds; \
maskLayer.path = maskPath.CGPath;\
View.layer.mask = maskLayer;

#endif /* ZQMacroViewHeader_h */
