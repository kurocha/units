# Teapot v2.2.0 configuration generated at 2017-10-12 18:49:03 +1300

required_version "2.0"

# Project Metadata

define_project "units" do |project|
	project.title = "Units"
	project.summary = 'A brief one line summary of the project.'
	
	project.description = <<-EOF
		Units description.
	EOF
	
	project.license = 'MIT License'
	
	project.add_author 'Samuel Williams', email: 'samuel.williams@oriontransfer.co.nz'
	# project.website = 'http://Units.com/'
	
	project.version = '0.1.0'
end

# Build Targets

define_target 'units-library' do |target|
	target.build do
		source_root = target.package.path + 'source'
		copy headers: source_root.glob('Units/**/*.{h,hpp}')
		build static_library: 'Units', source_files: source_root.glob('Units/**/*.cpp')
	end
	
	target.depends 'Build/Files'
	target.depends 'Build/Clang'
	
	target.depends :platform
	target.depends 'Language/C++14', private: true
	
	target.provides 'Library/Units' do
		append linkflags [
			->{install_prefix + 'lib/libUnits.a'},
		]
	end
end

define_target 'units-test' do |target|
	target.build do |*arguments|
		test_root = target.package.path + 'test'
		
		run tests: 'Units', source_files: test_root.glob('Units/**/*.cpp'), arguments: arguments
	end
	
	target.depends 'Language/C++14', private: true
	
	target.depends 'Library/UnitTest'
	target.depends 'Library/Units'
	
	target.provides 'Test/Units'
end

# Configurations

define_configuration 'development' do |configuration|
	configuration[:source] = "https://github.com/kurocha"
	configuration.import "units"
	
	# Provides all the build related infrastructure:
	configuration.require 'platforms'
	
	# Provides unit testing infrastructure and generators:
	configuration.require 'unit-test'
	
	# Provides some useful C++ generators:
	configuration.require 'generate-cpp-class'
	
	configuration.require "generate-project"
	configuration.require "generate-travis"
end

define_configuration "units" do |configuration|
	configuration.public!
end
