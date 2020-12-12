
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include<chrono>
#include <thread>
using namespace std;

__global__ void myfirstkernel(void) {
	printf("Hello CUDA \n");

}


__global__ void gpuAdd(int d_a, int d_b, int* d_c) {
	*d_c = d_a + d_b;
}


bool candy(std::vector<int>& ratings) {
	int size = ratings.size();
	if (size < 2)
	{
		return size;
	}
	std::vector<int> num(size, 1);
	for (int i = 1; i < size; i++) {
		if (ratings[i] > ratings[i - 1])
			num[i] = num[i-1]+1;
	}

	for (int i = size - 1; i > 0; --i) {
		if (ratings[i] < ratings[i - 1])
			num[i - 1] = std::max(num[i - 1], num[i] + 1);
	}
    
	for (auto i : num) {
		std::cout << i << std::endl;
	}
	return true;
}


bool testcandey() {

	std::vector<int> rating;
	rating.reserve(5);
	rating.push_back(1);
	rating.push_back(0);
	rating.push_back(2);
	rating.push_back(3);
	rating.push_back(4);
	candy(rating);
	return true;
}


vector<int> twosum(vector<int>& nums, int target) {
	int l = 0, r = nums.size()-1, sum;
	while (l<r)
	{
		sum = nums[l] + nums[r];
		if (sum == target)
			break;
		if (sum<target)
		{
			l++;
		}
		else
		{
			r--;
		}
	}
	return vector<int>{l, r};
}


bool testtwosum() {
	vector<int> numbers({ 2,7,11,15 });
	int target = 9;
	vector<int> results = twosum(numbers, target);
	for (auto result : results)
		cout << "the two sum is " << result << endl;

	return true;
}


int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	if (intervals.empty()) {
		return 1;
	}
	int n = intervals.size();
	sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {return a[1] < b[1]; });
	int total = 0, prev = intervals[0][1];
	for (int i = 1; i < intervals.size(); ++i)
	{
		if (intervals[i][0] < prev) {
			++total;
		}
		else
		{
			prev = intervals[i][1];
		}
	}
	return total;
}


bool testeraseOverlapIntervals(){
	std::vector<vector<int>> intervals;
	intervals.push_back({1,3});
	intervals.push_back({2,3});
	intervals.push_back({2,4});
	intervals.push_back({4,6});
	cout << "the total is " << eraseOverlapIntervals(intervals) << endl;
	return true;
}


vector<int> merge(vector<int>& nums1,int m, vector<int>& nums2,int n) {
	int pos = m + n-1;
	vector<int> results;
	results.reserve(pos);
	m = m - 1;
	n = n - 1;
	while (m>=0 && n>=0)
	{
		if (nums1[m] > nums2[n])
		{
			results.push_back(nums1[m]);
			m = m - 1;
		}
		else
		{
			results.push_back(nums2[n]);
			n = n - 1;
		}

	}
	while (m>=0)
	{
		results.push_back(nums1[m]);
		m = m - 1;
	}

	while (n >= 0)
	{
		results.push_back(nums2[n]);
		n = n - 1;
	}
	return results;
}

void testmerge() {
	vector<int> nums1({ 1,2,3 });
	vector<int> nums2({ 2,5,6 });
	vector<int> results = merge(nums1,nums1.size(),nums2,nums2.size());
	for (auto result : results)
		cout << "the merge is " << result << endl;
	
}


struct Node
{
	int val;
	Node* next;
	Node(int x) :val(x), next(nullptr) {
	}
};


Node* detectCircle(Node* head) {
	Node* fast = head, * slow = head;
	do {
		if (!fast || !fast->next) return nullptr;
		fast = fast->next->next;
		slow = slow->next;
	} while (fast != slow);

	fast = head;
	while (fast!=slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}


void testdetectCircle() {

	Node* head = new Node(22);
	Node* p=head;
	for (int i = 0; i < 5; i++) {
		Node* temp = new Node(i);
		p->next = temp;
		p = temp;
	}
	p->next = head->next->next;
	p = head;
	
	Node* pjoin = detectCircle(head);
	cout << pjoin->val << endl;
	//while (p)
	//{
	//	cout << p->val << endl;
	//	p = p->next;
	//}
	

}


string minWindow(string S, string T) {

	vector<int> chars(128, 0);
	vector<bool> flag(128, false);
	//先统计T中的字符情况
	for (int i = 0; i < T.size(); i++) {
		flag[T[i]] = true;
		++chars[T[i]];
	}

	//移动滑动窗口，不断更改统计数据
	int cnt = 0, l = 0, min_l = 0, min_size = S.size() + 1;
	for (int r = 0; r < S.size(); ++r) {
		if (flag[S[r]]) {
			if (--chars[S[r]] >= 0) {
				++cnt;
			}
		}
		
		//若目前滑动窗口已包含T中全部字符，
		//则尝试将l右移，在不影响结果的情况下获得最短字符串
		
		while (cnt == T.size())
		{
			if (r - l + 1 < min_size) {
				min_l = l;
				min_size = r - l + 1;
			}
			if (flag[S[l]] && ++chars[S[l]] > 0) {
				--cnt;
			}
			++l;
		}
		

	}
	return  min_size > S.size() ? "" : S.substr(min_l, min_size);
}


void testminwindow() {

	string s = "ADOBECODEBANC";
	string t = "ABC";
	string result = minWindow(s, t);
	cout << "the result is " << result << endl;
}


int mysqrt(int a) {
	if (a == 0)
		return a;
	int l = 0, r = a, mid,sqrt;
	while (l<r)
	{
		mid = l + 0.5 * (r - l);
		sqrt = a / mid;
		if (sqrt == mid)
			return mid;
		else if (sqrt > mid)
			l = mid;
		else
			r = mid;
	}
	return r;
}


void testsqrt()
{

	//int a = 100;
	int result = mysqrt(100);
	cout << "the result is " << result << endl;
}


//区间查找
int lower_bound(vector<int>& nums, int target) {
	int l = 0, r = nums.size(), mid;
	while (l<r)
	{
		mid = (l + r) / 2;
		if (nums[mid]>=target)
		{
			r = mid;
		}
		else
		{
			l = mid+1;
		}
	}
	return l;
}


int upper_bound(vector<int>& nums, int target) {
	int l = 0, r = nums.size(), mid;
	while (l < r)
	{
		mid = (l + r) / 2;
		if (nums[mid] > target)
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	return l;
}


vector<int> searchRange(vector<int>& nums, int target) {
	if (nums.empty()) return vector<int>{-1, -1};

	int lower = lower_bound(nums, target);
	int upper = upper_bound(nums, target) -1;
	if (lower == nums.size() || nums[lower] != target) {
		return vector<int>({ -1,-1 });
	}

	return vector<int>{lower, upper};
}


void testserachRange() {

	vector<int> nums({ 5,7,7,8,8,10 });
	vector<int> results = searchRange(nums, 8);
	for (auto result : results)
		cout << "the bound is " << result << endl;

}


//有序数组旋转二分查找
bool rotatevectorsearch(vector<int>& nums, int target) {
	int l = 0, r = nums.size()-1, mid;
	while (l<r)
	{
		mid = (l + r) / 2;
		if (nums[mid] == target) {
			return true;
		}
		if (nums[l] == nums[mid])
			++l;
		else if (nums[l]<nums[mid])
		{
			if (target > nums[l] && target < nums[mid])
				r = mid - 1;
			else
				l = mid + 1;

		}
		else if (nums[mid] < nums[r])
			{
				if (target > nums[mid] && target < nums[r])
		  
			        l = mid + 1;
	
			    else
			    	r = mid - 1;

		}
	}

	return false;
}


void testRotateVector() {
	vector<int> nums({2,5,6,0,0,1,2});
	bool result = rotatevectorsearch(nums, 10);
	cout << "the result is " << result << endl;
}

int add(int x, int y) {
	return x + y;
}

int callback(int x, int y, int(*func)(int, int)) {
	return (*func)(x, y);
}

;
__global__ void normkernel(float* src, float* dst, int nums) {
	
	int idx = blockIdx.x * blockDim.x + threadIdx.x;
	if (idx < nums) {
		//cout << src[idx] << endl;
		//dst[idx] = src[idx];
		dst[idx] = src[idx * 3];
		dst[nums + idx] = src[idx * 3 + 1];
		dst[2 * nums + idx] = src[idx * 3 + 2];
		printf("the dst valuse is %f \n", dst[idx]);
	}
}

void testnormkernel() {
	cudaError_t err = cudaSuccess;
	int numElements = 20*20*3;
	size_t size = numElements * sizeof(float);
	printf("[Vector addition of %d elements]\n", numElements);

	// Allocate the host input vector A
	float* h_A = (float*)malloc(size);

	// Allocate the host input vector B
	float* h_B = (float*)malloc(size);



	for (int i = 0; i < numElements; ++i) {
		h_A[i] = float(i);
	}

	float* d_A = NULL;
	err = cudaMalloc((void**)&d_A, size);

	float* d_B = NULL;
	err = cudaMalloc((void**)&d_B, size);

	err = cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
	

	int threadsPerBlock = 256;
	int blocksPerGrid = (numElements + threadsPerBlock - 1) / threadsPerBlock;
	printf("CUDA kernel launch with %d blocks of %d threads\n", blocksPerGrid, threadsPerBlock);
    normkernel <<<blocksPerGrid, threadsPerBlock >>> (d_A, d_B, numElements/3);
	//normkernel << <21, 256 >> > (d_A, d_B, numElements);
	err = cudaMemcpy(h_B, d_B, size, cudaMemcpyDeviceToHost);
	for (int i = 0; i < numElements; ++i) {
		cout<<h_B[i]<<endl;
	}
	err = cudaFree(d_A);
	err = cudaFree(d_B);

	free(h_A);
	free(h_B);

}


void add1(int a, int b, int& c, int thread) {
	c = a + b;
}

int main(void) {

	//static const int threads_nums = 10;
	//std::thread threads[threads_nums];
	//int c[threads_nums];
	//for (int i = 0; i < threads_nums; i++)
	//	threads[i] = std::thread(add1, i, i, c[i], i);
	//for (int i = 0; i < threads_nums; i++)
	//	threads[i].join();..



	testnormkernel();


	cin.get();
	//myfirstkernel<<<4, 4>>>();
	////printf("Hello CUDA \n");
	//int h_c;
	//int* d_c;
	//cudaMalloc((void**)&d_c, sizeof(int));
	//gpuAdd << <4, 4 >> > (1,4,d_c);
	//cudaMemcpy(&h_c, d_c, sizeof(int), cudaMemcpyDeviceToHost);
	//printf("the hc is %d", h_c);
	//cudaFree(d_c);

	testcandey();
	testeraseOverlapIntervals();
	testtwosum();
	testmerge();
	testdetectCircle();
	testminwindow();
	testsqrt();
	testserachRange();
	testRotateVector();


	

	return 0;
}