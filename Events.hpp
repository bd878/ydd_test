#pragma once

#include <memory>
#include <functional>

#include "EventParams.hpp"
#include "TimeFormat.hpp"
#include "Event.hpp"

class Events
{
public:
	using Function = std::function<void(const std::shared_ptr<Event>)>;

	struct Node {
		std::shared_ptr<Event> value;
		Node* next = nullptr;
	};

	~Events() {
		last = nullptr;
		for (Node* node = GetHead(); node; node = node->next) {
			PopFront();
		}
	}

	void InsertAfter(Node* node, std::shared_ptr<Event> value)
	{
		if (node == nullptr) {
			Node* newHead = new Node;
			newHead->value = value;
			newHead->next = head;
			head = newHead;
			last = newHead;
		} else {
			Node* newNode = new Node;
			newNode->value = value;
			newNode->next = node->next;
			node->next = newNode;
			if (newNode->next == nullptr) {
				last = newNode;
			}
		}
	}

	void PopFront() {
		if (head != nullptr) {
			Node* currentHead = head;
			head = head->next;
			delete currentHead;
		}
	}

	void Traverse(Function visit) {
		for (Node* node = GetHead(); node; node = node->next) {
			visit(node->value);
		}
	}

	Node* GetHead() { return head; }
	Node* GetLast() { return last; }
	const Node* GetHead() const { return head; }
	const Node* GetLast() const { return last; }

private:
	Node* head = nullptr;
	Node* last = nullptr;
};
