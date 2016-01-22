#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

string doc = "";
int cursor = 0;
bool isInsert = true;

void reset(){
	cursor = 0;
	doc = "";
	isInsert = true;
}

inline bool at_doc_end(){
	return cursor == doc.length();
}

inline bool isChar(char c){
	return c!=' ' && c!='\n' && c!='\t';
}

void left(){
	if(cursor > 0){
		cursor--;
	}
}

void right(){
	if(cursor<doc.length()){
		cursor++;
	}
}

bool at_1st_char_of_word(){
	if(cursor == 0){
		if(isChar(doc[cursor])) return true;
		else return false;
	}
	else if(isChar(doc[cursor]) && !isChar(doc[cursor-1])){
		return true;
	}
	return false;
}

void move_to_head_of_word(){
	while(cursor > 0 && !isChar(doc[cursor])) cursor--;
	while(cursor > 0 && isChar(doc[cursor-1])) cursor--;
}

int has_prev_word(){
	int pos = cursor;
	// cursor is in the 1st char of a word
	pos--;
	while(pos >= 0 && !isChar(doc[pos])) pos--;
	if(pos < 0) return -1;
	else{
		while(pos > 0 && isChar(doc[pos-1])) pos--;
		return pos;
	}
	
}

int has_next_word(){
	int pos = cursor;
	
	if(pos == doc.length()) return -1;

	while(pos < doc.length() && isChar(doc[pos])){
		pos++;
	}

	if(pos == doc.length()) return -1;	
	
	while(pos < doc.length() && !isChar(doc[pos])){
		pos++;
	}
	
	if(pos != doc.length()) return pos;
	else return -1;
}

void ctrl_left(){
	// what if cursor point to a space?
	if(isChar(doc[cursor-1])){
		while(cursor > 0 && isChar(doc[cursor-1])) cursor--;
	}
	else{
		int pos = cursor-1;
		while(pos > 0 && !isChar(doc[pos])) pos--;
		for(cursor = pos; cursor > 0 && isChar(doc[cursor-1]);){
			cursor--;
		}
	}
}

void ctrl_right(){
	int pos = has_next_word();
	if(pos >= 0){
		cursor = pos;
	}
}

void home(){
	while(cursor > 0 && doc[cursor-1] != '\n'){
		cursor--;
	}
}

void end(){
	while(!at_doc_end() && doc[cursor] != '\n'){
		cursor++;
	}
}

void insert(){
	isInsert = !isInsert;
}

void del(){
	if (!at_doc_end()){
		//cout << "here" << endl;
		doc.erase(cursor, 1);
	}
}

void backspace(){
	if(cursor != 0){
		doc.erase(cursor-1,1);
		cursor--;
	}
}

void blankspace(){
	if(isInsert){
		doc.insert(cursor, 1, ' ');
		cursor++;
	}
	else if(at_doc_end()){
		doc.append(1, ' ');
		cursor++;
	}
	else if(doc[cursor]=='\n'){
		doc.insert(cursor, 1, ' ');
		cursor++;
	}
	else{
		doc[cursor] = ' ';
		cursor++;
	}
}

void press(string &s){
	if(isInsert){
		doc.insert(cursor, s);
		cursor += s.length();
	}
	else{
		int pos = 0;
		while(pos < s.length() && cursor < doc.length() && doc[cursor]!='\n'){
			doc[cursor] = s[pos];
			cursor++;
			pos++;
		}
		if(pos == s.length()) return;
		string sub = s.substr(pos);
		doc.insert(cursor, sub);
		cursor += sub.length();
	}
}

void enter(){
	if(isInsert){
		doc.insert(cursor, 1, '\n');
		cursor++;
	}
	else if(at_doc_end()){
		doc.push_back('\n');
		cursor++;
	}
	else if(doc[cursor]=='\n'){
		doc.insert(cursor, 1, '\n');
		cursor++;
	}
	else{
		doc[cursor] = '\n';
		cursor++;
	}
}

char buf[10000] = {};
int main()
{
	doc.reserve(10000);
	string cmd;
	string s;
	reset();
	while(cin >> cmd){
		if(cmd == "Left"){
			left();
		} 
		else if(cmd == "Right"){
			right();
		} 
		else if(cmd == "CtrlLeft"){
			ctrl_left();
		} 
		else if(cmd == "CtrlRight"){
			ctrl_right();
		} 
		else if(cmd == "Home"){
			home();
		} 
		else if(cmd == "End"){
			end();
		} 
		else if(cmd == "Insert"){
			insert();
		} 
		else if(cmd == "Delete"){
			del();
			//cout << doc << "####" << endl;
		} 
		else if(cmd == "Backspace"){
			backspace();
		} 
		else if(cmd == "Blankspace"){
			blankspace();
		} 
		else if(cmd == "Press"){
			fgets(buf, 10000, stdin); int i;
	        buf[strlen(buf) - 1] = '\0';
	        for (i = 0; buf[i] && buf[i] == ' '; ++i);
	        if (buf[i]) {
	        	string s = string(&buf[i]);
	        	press(s);
	        }
			
			//cout << doc << "####" << endl;
		} 
		else if(cmd == "Enter"){
			enter();
		}
		else if(cmd == "EndWithEndl"){
			doc.append("\n");
			cout << doc << endl;
			reset();
		}
		else if(cmd == "EndOfInput"){
			break;
		}
	}
	//cout << doc ;	// endl ??
	return 0;
}

/*
#include <cstring>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
struct node {
    char ch;
    node *pre, *next;
};
node *head, *tail, *now;
int ins;
char buf[10000];
inline int isBlank(char ch) { return ch == ' ' || ch == '\t' || ch == '\n'; }
void Left() { if (now->pre != head) now = now->pre; }
void Right() { if (now->next) now = now->next; }
void CtrlLeft() {
    if (!isBlank(now->pre->ch))
        while (!isBlank(now->pre->ch) && now->pre != head)
            now = now->pre;
    else {
        node* p = now->pre;
        while (p->pre != head && isBlank(p->ch)) p = p->pre;
        if (p == head) return;
        for (now = p; !isBlank(now->pre->ch) && now->pre != head; )
            now = now->pre;
    } // end else
}
void CtrlRight() {
    if (now == tail) return;
    node* p = now->next;
    while (p->next && !isBlank(p->ch))
        p = p->next;
    if (p == tail) return;
    while (p->next && isBlank(p->ch))
        p = p->next;
    if (p == tail) return;
    now = p;
}
void Home() {
    while (now->pre != head && now->pre->ch != '\n')
        now = now->pre;
}
void End() {
    while (now->next && now->ch != '\n')
        now = now->next;
}
inline void Insert() { ins ^= 1; }
inline void Delete() {
    if (now == tail) return;
    node* p = now;
    now->pre->next = now->next;
    now->next->pre = now->pre;
    now = now->next;
    delete p;
}
inline void Backspace() {
    if (now->pre == head) return;
    node* p = now->pre;
    now->pre->pre->next = now;
    now->pre = now->pre->pre;
    delete p;
}
inline void Blankspace() {
    if (!ins && now != tail && now->ch != '\n') { now->ch = ' '; now = now->next; return; }
    node* p = new node(); p->ch = ' ';
    now->pre->next = p; p->pre = now->pre;
    p->next = now; now->pre = p;
}
void Press(char* str) {
    for (int i = 0; str[i]; ++i) {
        if (!ins && now != tail && now->ch != '\n') {
            now->ch = str[i]; now = now->next;
        } else {
            node* p = new node(); p->ch = str[i];
            now->pre->next = p; p->pre = now->pre;
            p->next = now; now->pre = p;
        } // enmd else
    } // end for
}
inline void Enter() {
    node* p = new node(); p->ch = '\n';
    now->pre->next = p; p->pre = now->pre;
    p->next = now; now->pre = p;
}
void go(char* cmd) {
    if (strcmp(cmd, "Left") == 0)
        Left();
    else if (strcmp(cmd, "Right") == 0)
        Right();
    else if (strcmp(cmd, "CtrlLeft") == 0)
        CtrlLeft();
    else if (strcmp(cmd, "CtrlRight") == 0)
        CtrlRight();
    else if (strcmp(cmd, "Home") == 0)
        Home();
    else if (strcmp(cmd, "End") == 0)
        End();
    else if (strcmp(cmd, "Insert") == 0)
        Insert();
    else if (strcmp(cmd, "Delete") == 0)
        Delete();
    else if (strcmp(cmd, "Backspace") == 0)
        Backspace();
    else if (strcmp(cmd, "Blankspace") == 0)
        Blankspace();
    else if (strcmp(cmd, "Enter") == 0)
        Enter();
    else if (strcmp(cmd, "Press") == 0) {
        fgets(buf, 10000, stdin); int i;
        buf[strlen(buf) - 1] = '\0';
        for (i = 0; buf[i] && buf[i] == ' '; ++i);
        if (buf[i]) Press(&buf[i]);
    } // end else
}
int main() {
    //      freopen("1.in", "r", stdin);
    head = new node(); tail = new node(); head->ch = tail->ch = 0;
    while (scanf("%s", buf) && strcmp(buf, "EndOfInput")) {
        ins = 1;
        head->next = tail; tail->pre = head;
        head->pre = tail->next = 0;
        for (now = tail, go(buf); scanf("%s", buf) && strcmp(buf, "EndWithEndl"); )
            go(buf);
        for (node* p = head->next; p != tail; p = p->next)
            printf("%c", p->ch);
        printf("\n\n");
        for (node* p = head->next; p != tail; ) {
            node* t = p; p = p->next;
            delete t;
        } // end for
    } // end while
    delete head; delete tail;
    return 0;
}
*/
