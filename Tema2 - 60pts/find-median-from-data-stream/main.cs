public class MedianFinder {
    PriorityQueue<int, int> maxHeap;
    PriorityQueue<int, int> minHeap;
    
    public MedianFinder() 
    {
        minHeap = new PriorityQueue<int, int>();
        maxHeap = new PriorityQueue<int, int>();
    }

    public void AddNum(int num) {
        minHeap.Enqueue(num, num);

        int varf = minHeap.Dequeue(); // va fi scos elementul maxim
        maxHeap.Enqueue(varf, -varf);

        if(Math.Abs(minHeap.Count - maxHeap.Count) > 1)
        {
            varf = maxHeap.Dequeue(); // va fi scos elementul minim
            minHeap.Enqueue(varf, varf); 
        }
    }
    
    public double FindMedian() 
    {
        double result = 0;
        if(minHeap.Count == maxHeap.Count)    
        {
            result = (minHeap.Peek() + maxHeap.Peek()) / 2.0;
        }
        else
        {
            result = maxHeap.Peek();
        }
        return result;
    }
}