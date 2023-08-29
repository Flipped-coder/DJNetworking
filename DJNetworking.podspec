

Pod::Spec.new do |spec|

  spec.name         = "DJNetworking"
  spec.version      = "0.1.3"
  spec.summary      = "这是一个网络库"

  spec.homepage     = "https://github.com/Flipped-coder/DJNetworking"


  # ―――  Spec License  ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  spec.license       = { :type => 'MIT', :file => 'LICENSE' }


  # ――― Author Metadata  ――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  spec.author             = { "邓杰" => "1171276417@qq.com" }


  # ――― Platform Specifics ――――――――――――――――――――――――――――――――――――――――――――――――――――――― #


  spec.ios.deployment_target = '13.0'


  # ――― Source Location ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #


  spec.source       = { :git => "https://github.com/Flipped-coder/DJNetworking.git", :tag => spec.version.to_s}


  # ――― Source Code ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  spec.source_files  = "DJNetworking/**/*.{h,m}"

  spec.public_header_files = "DJNetworking/**/*.h"


  # ――― Resources ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  # spec.resource  = "icon.png"
  # spec.resources = "Resources/*.png"

  # spec.preserve_paths = "FilesToSave", "MoreFilesToSave"


  # ――― Project Linking ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  spec.frameworks = 'UIKit', 'MapKit'



  # ――― Project Settings ――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }   # 解决x86库和arm64编译架构冲突

  spec.dependency 'AFNetworking', '~> 4.0.0'


end
