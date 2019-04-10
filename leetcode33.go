package main

import "fmt"

func main(){
	var nums =  [] int{1,3}
	var target int = 3
	fmt.Println(search(nums,target))
}

func search(nums []int, target int) int{
	var length int = len(nums)
	var l int = 0
	var r int = length - 1
	for l <= r {
		var mid int = (l + r) / 2
		if nums[mid] == target{
			return mid
		}
		if nums[mid] < nums[r]{ // 右半有序
			if nums[mid] < target &&  nums[r] >= target{
				l = mid + 1
			}else{
				r = mid - 1
			}
		}else{ //左半有序
			if nums[mid] > target && nums[l] <= target{
				r = mid - 1
			}else{
				l = mid + 1
			}
		}
	}
	return -1
}