Pod::Spec.new do |spec|

  spec.name         = "ZQMarcoBaseKit" # 项目名称

  spec.version      = "1.0.4" # 版本号 与 你仓库的 标签号 一致

  spec.summary      = "A set of useful Base Object for Foundation, UIKit and more." # 项目简介

  spec.homepage     = "https://github.com/zziqiang/ZQMarcoBaseKit" # 项目主页

  spec.license      = "MIT" # 开源证书

  spec.author             = { "zhengziqiang" => "a516969532@163.com" } # 作者信息

  spec.social_media_url   = "https://github.com/zziqiang" # 个人主页

  spec.platform     = :ios, "9.0" #平台及支持的最低版本

  spec.source       = { :git => "https://github.com/zziqiang/ZQMarcoBaseKit.git", :tag => spec.version } #你的仓库地址，不能用SSH地址

  spec.source_files  = "ZQMarcoBaseKit/**/*.{h,m}" # 代码的位置， ZQMarcoBaseKit/*.{h,m} 表示 ZQMarcoBaseKit 文件夹下所有的.h和.m文件

  spec.requires_arc = true # 是否启用ARC

  # spec.public_header_files = "Classes/**/*.h"

  # spec.resources = "Resources/*.png"

  spec.frameworks = "UIKit" # 依赖库


end
