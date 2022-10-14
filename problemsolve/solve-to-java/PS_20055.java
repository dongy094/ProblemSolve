package com.javalec.ex;

import java.util.Scanner;

public class Main {
	
	static int N,K;
	static int belt[];
	static int robot[]; // �κ� ���� ���� �� ��ġ ���
	
	static void moveBelt() {

		int tmp = belt[2*N];
		for(int i=2*N;i>1;--i) {
			belt[i] = belt[i-1];
		}
		belt[1] = tmp;

		for(int i=N;i>1;--i) {
			robot[i] = robot[i-1];
		}
		robot[N] = 0; // ��Ʈ ������ ��ġ�� �κ� ����(= �ش���ġ �κ�����:0)
		robot[1] = 0;
	}

	static void moveRobot() {
		for(int i=N;i>1;--i) {	// i:������
			if(belt[i]>=1 && robot[i]==0 && robot[i-1]==1) { // ������1�̻� and �κ�x�� �̵�����
				robot[i] = robot[i-1]; // �κ��̵�
				robot[i-1]=0;
				belt[i]--;		 	   // ������ 1 ����
			}
		}
		robot[N] = 0;
	}
	
	static void setRobot() {
		if(belt[1]!=0) { 
			robot[1] = 1;
			belt[1]--;
		}
	}
	
	static boolean check() {
		int cnt = 0;
		for(int i=1;i<=2*N;++i) {
			if(belt[i]==0) {
				cnt++;
			}
		}
		if(cnt>=K) {
			return true;
		}
		return false;
	}
	
	public static void main(String[] args){
		
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();
		belt = new int[2*N+1];
		robot = new int[N+1];
		for(int i=1;i<=2*N;++i) {
			belt[i] = sc.nextInt();
		}

		int level = 0;
		while(true) {
			level++;
			moveBelt();
			moveRobot();
			setRobot();
			if(check()) {
				System.out.println(level);
				return;
			}
		}
	}

}