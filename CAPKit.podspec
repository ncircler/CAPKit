Pod::Spec.new do |s|
  s.name         = "CAPKit"
  s.version      = "0.1.18"
  s.summary      = "CAPKit Framework."
  s.description  = <<-DESC
                   CAPKit Framework, Cloud Application Platform.
                   DESC
  s.homepage     = "https://github.com/successinfo-org/CAPKit"
  s.license      = "MIT"
  s.author       = { "samchang" => "sam.chang@me.com" }
  s.platform     = :ios, "7.0.0"
  s.source       = { :git => "https://github.com/successinfo-org/CAPKit.git", :tag => "v0.1.18" }
  s.frameworks   = 'AssetsLibrary', 'MessageUI', 'AddressBookUI', 'AddressBook', 'Accelerate', 'MapKit', 'AudioToolbox', 'CoreTelephony', 'QuickLook', 'Social', 'CoreLocation'
  s.weak_framework = 'WebKit'
  s.libraries = 'resolv'

  s.default_subspec = 'Release'

  s.subspec 'Release' do |ss|
    ss.resource = 'Debug/builtin'
    ss.ios.vendored_frameworks = 'Debug/CAPKit.framework'
  end

  s.subspec 'Resource' do |ss|
    ss.resource = 'Debug/builtin'
  end

  s.subspec 'Debug' do |ss|
    ss.resource = 'Debug/builtin'
    ss.ios.vendored_frameworks = 'Debug/CAPKit.framework'
  end

  s.dependency 'DTCoreText', '~> 1.6.12'
  s.dependency 'TouchJSON', '~> 1.1'
  s.dependency 'ASIHTTPRequest', '~> 1.8.2'
  s.dependency 'FMDB/FTS', '~> 2.6.2'
  s.dependency 'Reachability', '~> 3.1.1'
  s.dependency 'ZipArchive', '~> 1.4.0'
  s.dependency 'UIDevice-Hardware', '~> 0.1.3'
  s.dependency 'NSData+Base64', '~> 1.0.0'
  s.dependency 'ZBarSDK', '~> 1.3.1'
  s.dependency 'GZIP', '~> 1.0.2'
  s.dependency 'SSKeychain', '~> 1.2.2'
  s.dependency 'AnimatedGIFImageSerialization-fork', '~> 0.2.1'
  s.dependency 'Bugly', '~> 2.4.8'

  s.dependency 'CAPKit-iOS-WebP', '~> 0.4'
  s.dependency 'CAPKit-lua53', '~> 0.1.0'
  s.dependency 'CAPKit-3rdparty-libs', '~> 0.1.0'
  s.dependency 'CAPKit-sqlcipher', '~> 0.1.0'
  s.dependency 'CAPKit-OpenCV24x', '~> 2.4.10'
  s.dependency 'CAPKit-Box2D', '~> 0.1.0'
end
