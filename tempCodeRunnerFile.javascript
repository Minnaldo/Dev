function average(array){
    //함수를 완성하세요
      var tmp = 0;
      for(var i=0; i<array.length; i++)
          {
              tmp += parseFloat(array[i]);
          }
      var len = parseFloat(array.length);
      
    //   console.log(len);
      console.log(tmp/len);
  }
  
  console.log(average([1,2,3]));