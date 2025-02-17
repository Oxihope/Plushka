#include "Worker.h"

Contact_Info Worker::Get_Contact_Info() const {
	return Info;
}

string Worker::Get_Post() const{
	return Post;
}

void Worker::Set_Post(string post) {
	Post = post;
}