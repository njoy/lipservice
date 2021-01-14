
static std::optional<PairCorrelTuple> 
buildPairCorrelTuple( iRecordStream<char>& is, const Card5& card5 ){

  auto card17 = Card17( is );
  auto card18 = Card18( is, card17.nka );
  if (card5.nsk.value == 2){
    auto card19 = Card19( is );
    return PairCorrelTuple( card17, card18, card19 );
  }
  else {
    return PairCorrelTuple( card17, card18 );
  }

}
