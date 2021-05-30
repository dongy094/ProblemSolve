package com.javalec.ex;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;
import java.util.TreeSet;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		Set<Integer> set_arr = new TreeSet<Integer>();
		
		int cnt = 0;
		cnt = sc.nextInt();
		
		for(int i=0;i<cnt;++i) {
			int tmp = sc.nextInt();
			set_arr.add(tmp);
		}
		
		Iterator<Integer> it = set_arr.iterator();
		while(it.hasNext()) {
			System.out.print( it.next() + " " );
		}
		
		
//		ArrayList list_arr = new ArrayList(set_arr);
//		Collections.sort(list_arr);

		
		
//		for(int i=0;i<list_arr.size();++i) {
//			System.out.print( list_arr.get(i) + " " );
//		}
		
		sc.close();
	}

}
	