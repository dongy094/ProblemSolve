package com.javalec.ex;

import java.util.*;

public class Main {


	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int result = 0;
		int cnt = sc.nextInt();// input
		
		int[][] map = new int[cnt+1][cnt+1];

		
		for(int row=1;row<=cnt;++row) {
			
			for(int col=1;col<=row;++col) {
				
				map[row][col] = sc.nextInt();
				
				if(col==1) {
					map[row][col] = map[row][col] + map[row-1][col];
				}else if(col==row) {
					map[row][col] = map[row][col] + map[row-1][col-1];
				}else {
					map[row][col] = map[row][col] + Math.max(map[row-1][col-1], map[row-1][col] );				
				}
			
				
				if(result<map[row][col]) {
					result = map[row][col];
				}
			}
			
		}
		
		
		
		
		System.out.println(result);
		
	}

}
	