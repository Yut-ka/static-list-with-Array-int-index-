#pragma once
#include <string>
#include <iostream>

const int ARRAY_SIZE = 10;

struct TList_Item {
	int inf;
	int next;
};

struct Stat_List {
public:
	TList_Item Array[ARRAY_SIZE];
	int cout;
	Stat_List() {
		Array[0].next = 0;
		for (int i = 1; i < ARRAY_SIZE; i++) {
			Array[i].next = -1;
		}
		cout = 0;
	}
};

	int Push_after(Stat_List* list, int inf1, int inf2) {
		if (list->cout == ARRAY_SIZE - 1) return 2;
		int j;
		for (int i = 1; i < ARRAY_SIZE; i++) {
			if (list->Array[i].next == -1) { j = i; break; }
		}
		TList_Item* pCurrent = &list->Array[0];
		for (int i = 0; i <= list->cout; i++) {
			if (pCurrent->inf == inf1 || list->cout == 0) {
				list->Array[j].next = pCurrent->next;
				pCurrent->next = j;
				list->Array[j].inf = inf2;
				list->cout++;
				return 1;
			}
			pCurrent = &list->Array[pCurrent->next];
		}
		return 0;
	}
	int Push_before(Stat_List* list, int inf1, int inf2) {
		if (list->cout == ARRAY_SIZE - 1) return 2;
		int j;
		for (int i = 1; i < ARRAY_SIZE; i++) {
			if (list->Array[i].next == -1) { j = i; break; }
		}
		TList_Item* pCurrent = &list->Array[0];
		TList_Item* pPred = &list->Array[0];
		for (int i = 0; i <= list->cout; i++) {
			if (pCurrent->inf == inf1 || list->cout == 0) {
				list->Array[j].next = pPred->next;
				pPred->next = j;
				list->Array[j].inf = inf2;
				list->cout++;
				return 1;
			}
			pPred = pCurrent;
			pCurrent = &list->Array[pCurrent->next];
		}
		return 0;
	}

	int Delete(Stat_List* list, int inf) {
		TList_Item* pCurrent = &list->Array[0];
		TList_Item* pPred = &list->Array[0];
		for (int i = 0; i < list->cout; i++) {
			pPred = pCurrent;
			pCurrent = &list->Array[pCurrent->next];
			if (pCurrent->inf == inf) {
				pPred->next = pCurrent->next;
				pCurrent->next = -1;
				list->cout--;
				return 1;
			}
		}
		return 0;
	}

	int Get(Stat_List* list, int inf) {
		TList_Item pCurrent = list->Array[0];
		TList_Item pPred = list->Array[0];
		for (int i = 0; i < list->cout; i++) {
			pPred = pCurrent;
			pCurrent = list->Array[pCurrent.next];
			if (pCurrent.inf == inf) return pPred.next;
		}
		return -1;
	}
	std::string Show(Stat_List* list) {
		std::string str;
		int pCurrent = list->Array[0].next;
		while(pCurrent != 0) {
			str += " || " + std::to_string(list->Array[pCurrent].inf) + " || ";
			pCurrent = list->Array[pCurrent].next;
		}
		return str;
	}


