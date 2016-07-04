#pragma once
#include <string>
#include <vector>

class post {
private:
	int id;
	std::string title;
	std::string poster;
	std::string date;
	std::string text;
public:
	post();
	void printPost() const;
	post(std::string,std::string, int);
	post(int);
	int getID() const;
	std::string getPoster();
};

class thread {
private:
	std::string topic;
	std::string topicStarter;
	std::string date;
	std::vector<post> Posts;
public:
	std::string getTopic() const;
	std::vector<post> getPosts() const;
	thread(int);
	void createPost(int);
	thread(std::string, int);
	void print();
};

class forum {
private:
	std::string title;
	std::vector<thread> Threads;
	int fid;
public:
	forum();
	explicit forum(std::string);
	void createThread();
	std::vector<thread> getThreads();
	std::vector<post> getAllPosts();
	void createThread(std::string);
	void createPost();
	void print();
	void printPost(int);
	void printThread(std::string);
	int getFID();
};


