main=let s i=do w<-getLine;print$2^sum [1|c<-w,elem c "TDLF"];case i of 10->return();_->s$i+1 in s 1

main=interact$unlines.map(show.(2^).length.filter(`elem` "TDLF")).lines