// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int>& nums, int l, int r) {
	if (l + 1 >= r)
		return;
	int first = l, last = r - 1, key = nums[first];
	while (first < last)
	{
		while (first < last && nums[last] >= key) {
			--last;
		}
		nums[first] = nums[last];

		while (first < last && nums[first] <= key) {
			++first;
		}
		nums[last] = nums[first];
	}
	nums[first] = key;
	quicksort(nums, l, first);
	quicksort(nums, first + 1, r);
}


void testquicksort() {
	vector<int> nums({ 2,4,6,3,1,8,7 });
	quicksort(nums, 0, 7);
	for (auto num : nums) {
		cout << "the quick sort result is " << num << endl;
	}
}


void merge_sort(vector<int>& nums, int l, int r, vector<int>& temp) {
	if (l + 1 >= r) {
		return;
	}
	//divide
	int m = l + (r - l) / 2;
	merge_sort(nums, l, m, temp);
	merge_sort(nums, m + 1, r, temp);

	//conquer
	int p = l, q = m, i = l;
	while (p < m || q < r)
	{
		if (q >= r || (p < m && nums[p] <= nums[q])) {
			temp[i++] = nums[p++];
		}
		else
		{
			temp[i++] = nums[q++];
		}
	}

	for (i = l; i < r; ++i) {
		nums[i] = temp[i];
	}
}


void testmergesort() {
	vector<int> nums({ 2,4,6,3,1,8,7,1 });
	vector<int> temp(8, 0);
	merge_sort(nums, 0, 7, temp);
	for (auto num : nums) {
		cout << "the quick sort result is " << num << endl;
	}
}


void insertion_sort(vector<int>& nums, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j)
		{
			swap(nums[j], nums[j - 1]);
		}
	}
}


void testinsertion_sort() {
	vector<int> nums({ 2,4,6,3,1,8,7,1 });
	vector<int> temp(8, 0);
	insertion_sort(nums, nums.size());
	for (auto num : nums) {
		cout << "the quick sort result is " << num << endl;
	}
}


void bubble_sort(vector<int>& nums, int n) {
	for (int i = 1; i < n; ++i) {
		bool swaped = false;
		for (int j = 1; j < n - i + 1; ++j) {
			if (nums[j] < nums[j - 1]) {
				swap(nums[j - 1], nums[j]);
				swaped = true;
			}
		}
		if (!swaped)
		{
			break;
		}
	}
}


void testbubblesort() {
	vector<int> nums({ 2,4,6,3,1,8,7,1 });
	bubble_sort(nums, nums.size());
	for (auto num : nums) {
		cout << "the quick sort result is " << num << endl;
	}
}


void selection_sort(vector<int>& nums, int n) {
	int mid;
	for (int i = 0; i < n; i++) {
		mid = i;
		for (int j = i + 1; j < n; j++) {
			if (nums[j] < nums[mid])
				mid = j;
		}
		swap(nums[mid], nums[i]);
	}
}


void testselectionsort() {
	vector<int> nums({ 2,4,6,3,1,8,7,1 });
	selection_sort(nums, nums.size());
	for (auto num : nums) {
		cout << "the quick sort result is " << num << endl;
	}
}


int quickSelection(vector<int>& nums, int l, int r) {
	int i = l + 1, j = r;
	while (i < j)
	{
		while (i < j && nums[i] <= nums[l])
		{
			++i;
		}
		while (i < j && nums[j] >= nums[l])
		{
			j--;
		}
		swap(nums[i], nums[j]);
	}
	swap(nums[l], nums[j]);
	return j;
}


int findKthLargest(vector<int>& nums, int k) {

	int l = 0, r = nums.size() - 1, target = nums.size() - k;
	while (l < r)
	{
		int mid = quickSelection(nums, l, r);
		if (mid == target)
			return nums[mid];
		if (mid < target)
			l = mid + 1;
		else
			r = mid - 1;
	}

	return nums[l];

}


void testfindKthlargest() {
	vector<int> nums({ 3,2,1,5,6,4 });
	int result = findKthLargest(nums, 2);
	cout << "the K th Largest is " << result << endl;
}


int main()
{
	testquicksort();
	testmergesort();
	testinsertion_sort();
	testbubblesort();
	testselectionsort();
	testfindKthlargest();
    return 1;
}
