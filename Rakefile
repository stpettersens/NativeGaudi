# 
# Rakefile to build and test NativeGaudi on Travis CI.
# To build on your own system; please use `make` instead.
#

task :default => [:deps, :build, :test, :clean]

task :deps do
	puts "Get Boost libraries..."
	sh "sudo apt-get install libboost-dev"
	sh "sudo apt-get install libboost-regex-dev"
	puts "Get rapidjson library..."
	sh "wget https://rapidjson.googlecode.com/files/rapidjson-0.11.zip"
	sh "mkdir working"
	sh "unzip rapidjson-0.11.zip -d working"
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
