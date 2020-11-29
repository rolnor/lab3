#pragma once
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include<fstream>

using namespace std;

int insert_vector(vector<string>* v);
bool print_vector(const vector<string>* v);
bool initialise_database(vector<string>* v);
bool delete_vector(vector<string>* v);
bool search_vector(const vector<string>* v);
bool save(const vector<string>* v);
bool load(vector<string>* v);