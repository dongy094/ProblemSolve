package com.javalec.ex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	
	static class Number{
		Number(int num, int cnt){
			n = num;
			c = cnt;
		}
		int n,c;
	}
	
	static int R,C,K;
	static int[][] arr = new int[100][100];
	
	static int solve() {
		int rsize = 3, csize = 3;
		for(int t=0;t<=100;++t) {
			if(arr[R][C]==K) return t;
			if(rsize>=csize) {
				for(int i=0;i<rsize;++i) {
					List<Number> numList = new ArrayList<Number>();
					int[] cnt = new int[101];
					for(int j=0;j<csize;++j) {
						cnt[arr[i][j]]++;
					}
					
					for(int c=1;c<=100;++c) {
						if(cnt[c]>0) {
							numList.add(new Number(c,cnt[c]));
						}
					}
					numList.sort((lnum,rnum)->{
						return lnum.c - rnum.c;
					});
					
					int idx = 0;
					for(Number num : numList) {
						if(idx>=99) break;
						arr[i][idx++] = num.n;
						arr[i][idx++] = num.c;
					}
					csize = Math.max(csize, idx);
					for(;idx<100;++idx) {
						arr[i][idx] = 0;
					}
				}
			}else {
				for(int j=0;j<csize;++j) {
					List<Number> numList = new ArrayList<Number>();
					int[] cnt = new int[101];
					for(int i=0;i<rsize;++i) {
						cnt[arr[i][j]]++;
					}
					for(int c=1;c<=100;++c) {
						if(cnt[c]>0) {
							numList.add(new Number(c,cnt[c]));
						}
					}
					numList.sort((lnum,rnum)->{
						return lnum.c - rnum.c;
					});
					
					int idx = 0;
					for(Number num : numList) {
						if(idx>=99) break;
						arr[idx++][j] = num.n;
						arr[idx++][j] = num.c;
					}
					rsize = Math.max(rsize, idx);
					for(;idx<100;++idx) {
						arr[idx][j] = 0;
					}
				}
			}
		}
		
		
		return -1;
	}
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine());
		R = Integer.parseInt(st.nextToken()) - 1;
		C = Integer.parseInt(st.nextToken()) - 1;
		K = Integer.parseInt(st.nextToken());
		for(int i=0;i<3;++i) {
			st = new StringTokenizer(bf.readLine());
			for(int j=0;j<3;++j) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		System.out.println(solve());
		
	}
}
	