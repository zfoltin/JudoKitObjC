Pod::Spec.new do |s|
  s.name                  = 'JudoKitObjC'
  s.version               = '7.0.0'
  s.summary               = 'Judo Pay Full iOS Client Kit'
  s.homepage              = 'http://judopay.com/'
  s.license               = 'MIT'
  s.author                = { "Ashley Barrett" => 'ashley.barrett@judopayments.com' }
  s.source                = { :git => 'https://github.com/JudoPay/JudoKitObjC.git', :tag => s.version.to_s }
  
  s.documentation_url     = 'https://judopay.github.io/JudoKitObjC/'

  s.ios.deployment_target = '8.0'
  s.requires_arc          = true
  s.source_files          = 'Source/**/*.{m,h}'

  s.dependency 'DeviceDNA'

  s.frameworks            = 'CoreLocation', 'Security', 'CoreTelephony'
  s.pod_target_xcconfig   = { 'FRAMEWORK_SEARCH_PATHS'   => '$(inherited) ${PODS_ROOT}/DeviceDNA/Source' }

end
