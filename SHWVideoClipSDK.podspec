
Pod::Spec.new do |s|
  s.name             = 'SHWVideoClipSDK'
  s.version          = '0.2.0'
  s.summary          = '视频剪辑.'

  s.description      = <<-DESC
A videoClip sdk.
                       DESC
  s.homepage         = 'https://github.com/newsdata/SHWVideoClipSDK'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'shicahgnshun-xhzy' => 'shichangshun@xhzy' }
  s.source           = { :git => 'https://github.com/newsdata/SHWVideoClipSDK.git', :tag => s.version.to_s }
  #s.source           = { :path => '.' }

  s.ios.deployment_target = '12.0'

  s.source_files = 'SHWVideoClipSDK/Classes/*.{h,m}'
  s.public_header_files = 'SHWVideoClipSDK/Classes/*.h'
  
  # s.resource_bundles = {'SHWVideoClipSDK' => ['SHWVideoClipSDK/Assets/*']}
  
  s.vendored_frameworks = 'SHWVideoClipSDK/Frameworks/*.framework'
  
  # s.vendored_libraries = 'SHWVideoClipSDK/Frameworks/*.framework/*.a'
  s.static_framework = true
  
  s.resource = 'SHWVideoClipSDK/Assets/*.bundle'

  # s.public_header_files = 'Pod/Classes/**/*.h'
  s.frameworks = 'UIKit'
  
  s.dependency 'SHWMixMobile',    '0.2.6'
  s.dependency 'Realm'
  s.dependency 'MJExtension'
  
end
