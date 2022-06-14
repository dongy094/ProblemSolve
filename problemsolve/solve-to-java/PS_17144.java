package com.javalec.ex;

import java.util.Scanner;

public class Main {
	
	static int R,C,T;
	static int[][] arr = new int[50][50];	// ���� Ȯ�� �� ����û���� ����� �迭
	static int cleanRow;
	static int[] pointX = {0,0,-1,1};
	static int[] pointY = {-1,1,0,0};

	public static int solve() {
		
		for(int t=0;t<T;++t) {
			int[][] spray = new int[50][50]; // ���� Ȯ�� ���� �迭
			// Ȯ��(��� �迭�� ��ġ�鼭 ������ ������ �����¿� Ȯ��)
			for(int i=0;i<R;++i) {
				for(int j=0;j<C;++j) {
					if(arr[i][j]<5) continue;   // 5�̸��� Ȯ��Ǵ� ���� ����, ��� ������ �絵 �״�� �����Ѵ�.
					int quantity = arr[i][j]/5; // Ȯ��Ǵ� ��
					for(int k=0;k<4;++k) { 		// �����¿쿡 ������ Ȯ��� �� �ִ���
						int nx = pointX[k] + j;
						int ny = pointY[k] + i;
						if(nx>C-1 || nx<0 || ny>R-1 || ny<0) continue; // �����¿� �̵��� �迭�� ������ ����� skip
						if(arr[ny][nx] == -1) continue; //����û���� �ϰ�� skip
						spray[ny][nx] += quantity;
						spray[i][j] -= quantity;
					}
				}
			}
			
			// Ȯ��Ȱ��� ���� �迭�� ��ġ��
			for(int i=0;i<R;++i) {
				for(int j=0;j<C;++j) {
					arr[i][j] += spray[i][j];
				}
			}
			
			// ����û���� ������(�̼������̵�) ��
			for(int i=cleanRow-1;i>=1;--i) {
				arr[i][0] = arr[i-1][0];
			}
			for(int j=0;j<=C-2;++j) {
				arr[0][j] = arr[0][j+1];
			}
			for(int i=0;i<=cleanRow-1;++i) {
				arr[i][C-1] = arr[i+1][C-1];
			}
			for(int j=C-1;j>=2;--j) {
				arr[cleanRow][j] = arr[cleanRow][j-1];
			}
			arr[cleanRow][1] = 0;
			
			// ����û���� ������(�̼������̵�) ��
			for(int i=cleanRow+2;i<=R-2;++i) {
				arr[i][0] = arr[i+1][0];
			}
			for(int j=0;j<=C-2;j++) {
				arr[R-1][j] = arr[R-1][j+1];
			}
			for(int i=R-1;i>=cleanRow+2;--i) {
				arr[i][C-1] = arr[i-1][C-1];
			}
			for(int j=C-1;j>=2;--j) {
				arr[cleanRow+1][j] = arr[cleanRow+1][j-1];
			}
			arr[cleanRow+1][1] = 0;
		}
		
		int result = 0;
		for(int i=0;i<R;++i) {
			for(int j=0;j<C;++j) {
				if(arr[i][j] > 0) {
					result += arr[i][j];
				}
				
			}
		}
		
		return result;
	}
	
	public static void main(String[] args){
	
		Scanner sc = new Scanner(System.in);
		R = sc.nextInt();
		C = sc.nextInt();
		T = sc.nextInt();
		
		for(int i=0;i<R;++i) {
			for(int j=0;j<C;++j) {
				arr[i][j] = sc.nextInt();
				if(arr[i][j]==-1 && arr[i-1][j]==-1) {
					cleanRow = i-1; // ����û���� ��ġ(���ϵ�ĭ�� ����ĭ)
				}
			}
		}
		
		System.out.println(solve());
	}
	
}
	