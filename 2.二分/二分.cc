//二分的本质不是单调性
//有一个性质能使一半满足，另一半不满足就可以使用二分


//整数模板
//第一种情况
//当满足check条件的情况都在右边
//mid = l+r+1>>1
//if(check(mid)) 
//      true:[mid,r]    l=mid
//      false:[l,mid-1] r=mid-1

//第二种情况
//当满足check条件的情况都在左边
//mid = l+r>>1
//if(check(mid))
//      true:[l,mid]    r=mid
//      false:[mid+1,r] l=mid+1

//根据自己需要的结果在左边或右边决定采用第二个模板还是第一个模板



//浮点数模板
//mid = l+r>>1
//if(check(mid)) 
//      true:[mid,r]    l=mid
//      false:[l,mid-1] r=mid
