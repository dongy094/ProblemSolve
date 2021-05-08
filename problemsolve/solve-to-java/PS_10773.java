package com.javalec.ex;

import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	
	public static void solve() {
		System.out.println("hello");
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		Stack<Integer> stack = new Stack<Integer>();
		
		int k = sc.nextInt();
		for(int i=0;i<k;++i) {
			
			int tmp = sc.nextInt();
			if(tmp != 0) {
				stack.push(tmp);
			}else {
				if(!stack.empty()) {
					stack.pop();
				}
				
			}
			
		}

		int size = stack.size();
		int sum = 0;
		for(int i=0;i<size;++i) {
			sum += stack.peek();
			stack.pop();
		}
		
		System.out.println(sum);
		
		sc.close();
	}

}
	