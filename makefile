f ?= A.cpp
dir ?= codechef

cpp:
	g++ $(dir)/$(f).cpp -o out
	./out

cpp-i:
	g++ $(dir)/$(f).cpp -o out
	./out < input

java:
	javac $(dir)/$(f).java
	java $(f)

java-i:
	javac $(dir)/$(f).java
	java $(f) < input

py3:
	python3 $(dir)/$(f).py

py3-i:
	python3 $(dir)/$(f).py < input