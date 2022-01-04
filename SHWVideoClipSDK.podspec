
Pod::Spec.new do |s|
  s.name             = 'SHWVideoClipSDK'
  s.version          = '0.1.0'
  s.summary          = '视频剪辑.'

  s.description      = <<-DESC
A videoClip sdk.
                       DESC
  s.homepage         = 'https://github.com/newsdata/SHWVideoClipSDK'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'shicahgnshun-xhzy' => 'shichangshun@xhzy' }
  s.source           = { :git => 'https://github.com/newsdata/SHWVideoClipSDK.git', :tag => s.version.to_s }
  s.source           = { :path => '.' }

  s.ios.deployment_target = '9.0'

  s.source_files = 'SHWVideoClipSDK/Classes/*.{h,m}'
  s.public_header_files = 'SHWVideoClipSDK/Classes/*.h'
  
  # s.resource_bundles = {'SHWVideoClipSDK' => ['SHWVideoClipSDK/Assets/*']}
  
  s.vendored_frameworks = 'SHWVideoClipSDK/Frameworks/*.framework'
  
  # s.vendored_libraries = 'SHWVideoClipSDK/Frameworks/*.framework/*.a'
  s.static_framework = true
  
  s.resource = 'SHWVideoClipSDK/Assets/*.bundle'

  # s.public_header_files = 'Pod/Classes/**/*.h'
  s.frameworks = 'UIKit'
  
  s.dependency 'AFNetworking'
  s.dependency 'Masonry', '1.1.0'
  s.dependency 'MBProgressHUD', '~>1.1.0'
  s.dependency 'JXCategoryView', '1.5.2'
  s.dependency 'RealReachability', '1.3.0'
  s.dependency 'BlocksKit', '2.2.5'
  s.dependency 'Aspects', '1.4.1'
  s.dependency 'YYCategories', '1.0.4'
  s.dependency 'QTEventBus', '0.4.0'
  s.dependency 'YYCache', '1.0.4'
  s.dependency 'SSZipArchive'

  s.dependency 'MJExtension'
  s.dependency 'SHWMixMobile',    '0.2.6'
  s.dependency 'Realm'
  
end
