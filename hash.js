//simple hashtable imp using js

class HashTable{
   
    constructor (Size=53){
        this.keyMap=new Array(Size);
        this.index=[];
        let arr=[];
        console.log(arr)
    }
    // this is the main hashing function 
    _hash(key){

        let total=0;
        let pr=31;
        for (let i=0;i<Math.min(key.length,100);i++){
            let char=key[i]
            let value=char.charCodeAt(0)-96 
            // the main logic that gives the result of the hashed result
            total=(total*pr+value)%this.keyMap.length;
           
    
        }
        return total;
    }
    set (key,value){
        this.index.push(this._hash(key));
        if (!this.keyMap[this._hash(key)]){
            this.keyMap[this._hash(key)]=[];
        }
        this.keyMap[this._hash(key)].push([key,value]);
    }
    get (key){
       let  _newIndex=this._hash(key);
    //    console.log(this.keyMap[_newIndex][0][0])
       if(this.keyMap[_newIndex]){
        if(this.keyMap[_newIndex].length==1){
            return this.keyMap[_newIndex][0][1]

        }
        else{
        for(let i=0;i<this.keyMap[_newIndex].length;i++){
            if(this.keyMap[_newIndex][i][0]==key){
                return this.keyMap[_newIndex][i][1];
           
        }}
    }
    return undefined      
    }
}
     keys(){
         let arr=[];

         for(let i=0;i<this.keyMap.length;i++){
             if(this.keyMap[i]){
                 for (let j=0;j<this.keyMap[i].length;j++){
                     if(!(arr.includes(this.keyMap[i][j][0] ))){
                        arr.push(this.keyMap[i][j][0]);

                     }  
                 }
                 
             }
         }
         return arr; 
     }
     values(){
        let arr=[];

        for(let i=0;i<this.keyMap.length;i++){
            if(this.keyMap[i]){
                for (let j=0;j<this.keyMap[i].length;j++){
                    if(!(arr.includes(this.keyMap[i][j][1] ))){
                       arr.push(this.keyMap[i][j][1]);

                    }
    
                   
                }
                
            }
        }
        return arr;
      






     }



}









