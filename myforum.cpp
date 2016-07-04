#include "myforum.h"
#include <iostream>
#include <ctime>

using namespace std;
const string Creators[5] = { "John","George","Michael","Jennifer","Alice" };
const string Text[4] = { "Hello world!!","HELP I NEED YOUR HELP MY PC WONT BOOT!!!","This is an example","Hello fellas my name is Bond,James Bond" };
const string Titles[5] = { "Example Title","OMG I MADE IT!","Im DAB","I have no idea!","Gotta catch 'em all!" };

string getDate() {
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "%d-%m-%Y", timeinfo);
	return string(buffer);
}

/*Post Implementation*/
post::post() {
	id = 10;
	cout << "Enter post's title:";
	getline(cin, title);
	cout << "Enter poster's name:";
	getline(cin, poster);
	cout << "Enter desired text:" << endl;
	getline(cin, text);
	date = getDate();
	printPost();
}

void post::printPost() const {
	cout << "Post(id=" << id << ") " << title << " was created by " << poster << " on " << date << endl;
	cout << "Text:" << endl;
	cout << text << endl << endl;
}

post::post(string creator, string topic, int fid) {
	id = fid;
	title = topic;
	poster = creator;
	date = getDate();;
	text = Text[rand() % 4];
	printPost();
}

post::post(int fid) {
	title = Titles[rand() % 5];
	date = getDate();
	string Poster = Creators[rand() % 4];
	text = Text[rand() % 4];
	poster = Poster;
	id = fid;
	printPost();
}

int post::getID() const {
	return id;
}

std::string post::getPoster() {
	return poster;
}

/*Thread Implementation*/
inline string thread::getTopic() const {
	return topic;
}

thread::thread(int fid) {
	topic = Titles[rand() % 5];
	date = getDate();
	string TS = Creators[rand() % 5];
	topicStarter = TS;
	cout << "Thread with subject: " << topic << " has just been created" << endl;
	post newPost(TS, Titles[rand() % 5], fid);
	Posts.push_back(newPost);
}

void thread::createPost(int fid) {
	post newPost(fid);
	Posts.push_back(newPost);
}

thread::thread(string title, int fid) {
	topic = title;
	date = getDate();
	string TS = Creators[rand() % 4];
	topicStarter = TS;
	cout << "Thread with subject: " << topic << " has just been created" << endl;
	post newPost(TS, Titles[rand() % 5], fid);
	Posts.push_back(newPost);
}

void thread::print() {
	vector<string>::size_type i;
	cout << topic << "||TS: " << topicStarter << " on " << date << endl;
	cout << "Thread's post(s):" << endl;
	for (i = 0; i < Posts.size(); i++) {
		cout << i + 1 << ":";
		Posts[i].printPost();
		cout << endl;
	}
}

vector<post> thread::getPosts() const {
	return Posts;
}
/*Forum Implementation*/
void forum::printPost(int ID) {
	if (Threads.size() == 0)
		cout << "Forum is empty!" << endl;
	else {
		for (vector<thread>::size_type i = 0; i < Threads.size(); i++) {
			vector<post> currPosts = Threads[i].getPosts();
			for (vector<post>::size_type j = 0; j < currPosts.size(); j++) {
				if (currPosts[j].getID() == ID) {
					currPosts[j].printPost();
					return;
				}
			}
		}
		cout << "Post with ID:" << ID << " doesn't exist." << endl;
	}
}

void forum::print() {
	cout << "---------------------------------------------------------------------------------------------------------" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << title << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	if (Threads.size() == 0)
		cout << "Forum is empty!" << endl;
	else {
		for (vector<thread>::size_type i = 0; i < Threads.size(); i++) {
			cout << i + 1 << ". " << Threads[i].getTopic() << endl;
		}
	}
	cout << "---------------------------------------------------------------------------------------------------------" << endl;
}

forum::forum() {
	fid = 1;
	cout << "Enter forum's name:";
	getline(cin, title);
	cout << title << " has just been created!" << endl;
}

forum::forum(string name) {
	fid = 1;
	title = name;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << title << " has just been created!" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void forum::createThread() {
	thread newThread(fid);
	Threads.push_back(newThread);
	fid++;
}

vector<thread> forum::getThreads() {
	return Threads;
}

vector<post> forum::getAllPosts() {
	vector<thread> forumThreads = this->getThreads();
	vector<post> allPosts;
	vector<post> temp;
	for (vector<thread>::size_type i = 0; i < forumThreads.size(); i++) {
		temp = forumThreads[i].getPosts();
		allPosts.insert(allPosts.end(), temp.begin(), temp.end());
	}
	return allPosts;
}

void forum::createThread(string threadTitle) {
	thread newThread(threadTitle, fid);
	Threads.push_back(newThread);
	fid++;
}

void forum::createPost() {
	Threads[rand() % Threads.size()].createPost(fid);
	fid++;
}

void forum::printThread(string thread) {
	vector<string>::size_type i;
	bool found = false;
	for (i = 0; i < Threads.size(); i++) {
		if (thread == Threads[i].getTopic()) {
			found = true;
			break;
		}
	}
	if (found)
		Threads[i].print();
	else
		cout << "Thread: " << thread << " doesnt exist!!!" << endl;
}

int forum::getFID() {
	return fid;
}