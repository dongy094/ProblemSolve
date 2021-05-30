package com.javalec.ex;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
			
		int cnt = 0;
		List list_a = new ArrayList();
		List list_b = new ArrayList();
		
		Scanner sc = new Scanner(System.in);
		
		cnt = sc.nextInt();
		for(int i=0;i<cnt;++i) {
			list_a.add(sc.nextInt());
		}
		Collections.sort(list_a);
		
		for(int i=0;i<cnt;++i) {
			list_b.add(sc.nextInt());
		}
		Collections.sort(list_b);
		
		
		int sum = 0;
		for(int i=0;i<cnt;++i) {
			int tmp_a = (int) list_a.get(i);
			int tmp_b = (int) list_b.get(list_b.size()-i-1);
			sum += tmp_a * tmp_b;
		}
		
		System.out.println(sum);
		
		
	}

}
	