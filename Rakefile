# 
# Rakefile to build and test NativeGaudi on Travis CI.
# To build on your own system; please use `make` instead.
#

task :default => [:deps, :build, :test, :clean]

task :deps do
	puts "Get Boost libraries..."
	sh "sudo apt-get install libboost-dev"
	puts "Get rapidjson library..."
	puts "TODO..."
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
