package com.javalec.ex;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	
//	public static void solve() {
//		System.out.println("hello");
//	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int cnt_num = 5;
		int sum = 0;
		int mid = (cnt_num/2);
		int[] arr = new int[cnt_num];
		for(int i=0;i<cnt_num;++i) {
			int tmp = sc.nextInt();
			arr[i] = tmp;
			sum += tmp;
		}
		sum = sum / cnt_num;
		System.out.println(sum);
		
		Arrays.sort(arr);
		System.out.println(arr[mid]);
		
		sc.close();
	}

}
	