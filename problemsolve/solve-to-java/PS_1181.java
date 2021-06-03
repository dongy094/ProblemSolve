package com.javalec.ex;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Main {


	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		Set<String> s = new HashSet<String>();

		int cnt = sc.nextInt();
		for(int i=0;i<cnt;++i) {
			s.add(sc.next());
		}
		
		List<String> str_list = new ArrayList<String>(s);
		Collections.sort(str_list, new Comparator<String>() {

			@Override //t1매개변수가 기준인듯
			public int compare(String t1, String t2) {
				if(t1.length() > t2.length()) {
					return 1; // 리턴값 1이면 오름차순, 이외는 그상태 유지
				}else if(t1.length() < t2.length()) {
					return -1; 
				}else {
					return t1.compareTo(t2);
					// 1이면 사전순 정렬
				}
			}	
		});
		

		for(String ss : str_list) {
			System.out.println(ss);
		}
		

	}

}
	