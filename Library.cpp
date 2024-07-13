#include "Library.h"


Library::Library() {
	this->books = new Book;
	this->length = 0;
	this->counter = -1;
}


void Library::addBook(const Book& book) {
	this->length++;
	this->counter++;
	Book* tmp = new Book[this->length];
	for (int i = 0; i < this->counter; i++) {
		tmp[i] = this->books[i];
	}
	tmp[this->counter] = book;
	for (int i = 0; i < this->counter; i++) {
		this->books[i].~Book();
	}
	this->books = tmp;
}


Book Library::removeBook(long long isbn) {
	Book deletedBook;
	this->counter--;
	this->length--;
	int iForBooks = 0;
	Book* tmp = new Book[this->length];
	for (int i = 0; i < this->counter + 1; i++) {
		if (isbn == this->books[i].isbn()) {
			deletedBook = this->books[i];
			iForBooks++;
		}
		tmp[i] = this->books[iForBooks];
		iForBooks++;
	}
	for (int i = 0; i < this->counter; i++) {
		this->books[i].~Book();
	}
	this->books = tmp;
	return deletedBook;
}


void Library::displayAllBooks() {
	for (int i = 0; i < this->counter + 1; i++) {
		this->books[i].displayDetails();
	}
}


Book* Library::findBook(long long isbn) {
	for (int i = 0; i < this->counter + 1; i++) {
		if (this->books[i].isbn() == isbn) {
			return new Book(this->books[i]);
		}
	}
	return new Book;
}