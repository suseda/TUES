class Vector
{
   int[] values;
   int capacity,size;


   public Vector(int []values_input,int capacity_input,int size_input)
   {
        this.size=size_input;
        this.capacity=capacity_input;
        this.values_input=new int[capacity_input];
	for (int i = 0; i < size_input; i++) 
	{
	  this.values[i]=values_input[i];
	}
	return this;
   }	
   
   
   public void resize()
   {
   	this.capacity=this.capacity*2;
   	int[] val=new int[this.capacity];
   }
   
   public void add(int value)
   {
   	if(this.size==this.capacity)
   	{
   		resize();
   	}
   	this.values[this.size]=value;
   	this.size+=1;
   }

}
