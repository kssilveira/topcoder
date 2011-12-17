import java.math.BigInteger;
import java.math.BigDecimal;
import java.lang.Math;
import java.util.LinkedList;
import java.util.ListIterator;

class IsolatedPrimes {
	int lastX = 0;
	BigInteger lastRes;

	public String findPrime(int x, int a, int b) {
		//System.out.println("lastX: " + lastX);
	
		BigInteger // best: [1.859375, 1.86132812) //now: 1.86035156
							 //f = (new BigDecimal(Math.min(Math.exp((b + a + 1 - 1.859375 * x) / (double) x), Math.pow(2, 62.75)))).toBigInteger(),
							 f = BigInteger.valueOf(a + 2),
							 p = f.subtract(BigInteger.valueOf(a + 1)),
							 aBig = BigInteger.valueOf(a + 2),
							 raBig = BigInteger.valueOf(a),
							 bBig = BigInteger.valueOf(b),
							 minBig = BigInteger.valueOf(0);
		
		if(x == lastX) {
			f = lastRes;
			p = f.subtract(BigInteger.valueOf(a + 1));
		}
		lastX = x;
		
		//System.out.println("f: " + f);
		//System.out.println("p: " + p);
		
		LinkedList listAllPrimes = new LinkedList(),
							 listCandidatePrimes = new LinkedList();
		boolean still = true;
		int tries = 0, min = 999999999;
		
		while(p.compareTo(f) < 0) {
			listAllPrimes.add(p);
			p = p.nextProbablePrime();
		}
		
		/*
		for(int i = 0; i < x; i++) {
			listAllPrimes.add(p);
			p = p.nextProbablePrime();
		}//*/
		
		//while(still) {
		while(true) {
			/*
			tries++;
			if(tries % 1000 == 0)
				System.out.println("tries: " + tries + "min: " + min + "big: " + minBig.toString());
			//*/
			
			listAllPrimes.add(p);
			
			if(aBig.compareTo(p) <= 0) {
				listCandidatePrimes.add(p);
			}
			if(!listCandidatePrimes.isEmpty()) {
				while(p.compareTo(bBig.add((BigInteger)listCandidatePrimes.peek())) >= 0) {
					BigInteger curP = (BigInteger) listCandidatePrimes.remove(),
										 first = curP.subtract(raBig),
										 last = curP.add(bBig);
					int numOfPrimes = 0;
					while(first.compareTo((BigInteger)listAllPrimes.peek()) > 0) {
						listAllPrimes.remove();
					}
					for(ListIterator itr = listAllPrimes.listIterator();
							itr.hasNext();) {
						if(((BigInteger) itr.next()).compareTo(last) <= 0) {
							numOfPrimes++;
						} else {
							break;
						}
					}
					//System.out.println(curP + ": " + numOfPrimes);
					if(numOfPrimes <= x) {
						lastRes = curP;
						
						return curP.toString();
						//still = false;
						//break;
					}
					/*
					if(numOfPrimes < min) {
						min = numOfPrimes;
						minBig = curP;
						//System.out.println("min: " + min + " big: " + minBig.toString());
						System.out.print(min + " ");
					}//*/
				}
			}
			
			p = p.nextProbablePrime();
		}
		/*
		System.out.println("listAllPrimes:");
		while(!listAllPrimes.isEmpty()) {
			System.out.println(listAllPrimes.remove());
		}
		
		System.out.println("listCandidatePrimes:");
		while(!listCandidatePrimes.isEmpty()) {
			System.out.println(listCandidatePrimes.remove());
		}
		
		return "0";//*/
	}
}
