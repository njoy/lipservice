struct Suff {
  using Value_t = double;
  static std::string name(){ return "suff"; }

  static std::string description(){
    return
        "The suff parameter specifies the suffix of the ZAID. It is appended \n"
        "to the ZA for the material. \n"
        "\n"
        "It is a two-digit float (e.g., .70, .71, .80). The \n"
        "default value is .00. \n"
        "\n"
        "Specifying a negative value when iopt=7--9 leaves the old \n"
        "ZAID unchanged (from previous ACER run).";
  }

  static Value_t defaultValue(){ return 0.00; }
  static bool verify( Value_t s ){
    if( s <= 0.0 ){
      return true;
    } else if ( ( s  < 1.0 ) and ( s > 0.009 ) ){
      if( static_cast<int>(std::round(s*100))%100 == double(s*100) ) { return true; }
  }

    return false;
  }
};
