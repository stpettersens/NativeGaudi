# 
# Rakefile to build and test NativeGaudi with Travis CI.
# This is basically a wrapper around the true Makefile,
# but it does also retrieve the dependencies.
# That is the Boost libraries via APT and the rapidjson library from Google Code.
#

task :default => [:deps, :build, :test, :clean]

task :deps do
	puts "Get Boost libraries..."
	sh "sudo apt-get install libboost-dev"
	sh "sudo apt-get install libboost-regex-dev"
	puts "Get rapidjson library..."
	sh "wget https://rapidjson.googlecode.com/files/rapidjson-0.11.zip"
	sh "mkdir working"
	sh "unzip -qq rapidjson-0.11.zip -d working"
	sh "cp -r working/rapidjson/include/rapidjson src"
	sh "rm -f -r working *.zip"
end

task :build do
	sh "make"
end

task :test do
	sh "make test"
end

task :clean do
	sh "make clean"
end
