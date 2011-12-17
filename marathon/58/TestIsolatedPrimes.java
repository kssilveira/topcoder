import java.util.Random;
import java.io.FileWriter;
import java.io.PrintWriter;

class IsolatedPrimesThread extends Thread {
	int x, a, b;
	IsolatedPrimes isolatedPrimes;
	String result;
	IsolatedPrimesThread(int x, int a, int b,
											 IsolatedPrimes isolatedPrimes) {
		this.x = x;
		this.a = a;
		this.b = b;
		this.isolatedPrimes = isolatedPrimes;
	}
	public void run() {
		result = isolatedPrimes.findPrime(x, a, b);
	}
	public String getResult() {
		return result;
	}
}


class TestIsolatedPrimes {
	static final int MAX_TIME = 20000;
	static final IsolatedPrimes isolatedPrimes = new IsolatedPrimes();
	static PrintWriter out;
	
	public static void main(String[] args) throws java.io.IOException {
		out = new PrintWriter(new FileWriter("out.txt", true), true);
		out.println("-----------------------");
				
		//x = Integer.parseInt(args[0]);
		//a = Integer.parseInt(args[1]);
		//b = Integer.parseInt(args[2]);
		
		for(int x = 1; x <= 500; x++) {
			for(int k = 4; k <= 25; k++) {
				test(x, k * x, k * x, 0 * MAX_TIME);
			}
		/*
			for(int a = 4 * x; a <= 25 * x; a++) {
				for(int b = 4 * x; b <= 25 * x; b++) {
					test(x, a, b, MAX_TIME);
				}
			}//*/
		}
		
		//testExamples();
		//testRandom();
	}
	
	static void testRandom() {
		Random r = new Random(7);
		for(int i = 0; i < 100; i++) {
			int x = randomBetween(1, 500, r),
					a = randomBetween(4 * x, 25 * x, r),
					b = randomBetween(4 * x, 25 * x, r);
			test(x, a, b, MAX_TIME);
		}
	}
	
	static int randomBetween(int a, int b, Random r) {
		return r.nextInt(b - a + 1) + a;
	}
	
	static void testExamples() {
		int[] x = {2,  410,  400,  87,   76,  312,  449,   489,  126,   500, 0},
					a = {5, 5954, 4067, 922, 1127, 7649, 3232, 11822, 2399, 12500},
					b = {5, 1916, 9810, 630,  546, 4383, 8777,  8438, 1183, 12500};
		
		for(int i = 0; x[i] != 0; i++)
			test(x[i], a[i], b[i], 30000);
	}
	
	static void test(int x, int a, int b, int maxTime) {
		System.out.print("Result to (" + x + ", " + a + ", " + b + ")");
		long startTime, endTime;
		IsolatedPrimesThread t = new IsolatedPrimesThread(x, a, b, isolatedPrimes);
		startTime = System.currentTimeMillis();
		t.start();
		try {
			t.join(maxTime);
		} catch(Exception e) {
		}
		endTime = System.currentTimeMillis();
		t.stop();
		System.out.println(" is " + t.getResult() + " in " + (endTime - startTime) + "ms.");
		out.println("" + x + " " + a + " " + b + " " + t.getResult());
	}
}