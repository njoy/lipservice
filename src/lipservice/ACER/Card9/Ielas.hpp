struct Ielas {
  using Value_t = int;
  static std::string name(){ return "ielas"; }

  static std::string description() {
    return
        "The ielas argument specifies whether the elastic scattering is \n"
        "coherent, incoherent or both.\n"
        "\n"
        "A value of 0 specifies coherent scattering, a value of 1 \n"
        "specifies incoherent scattering and a value of 2 specifies both.\n"
        "The default value is 0.";
  }

  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t& ielas ){
    return ( ielas == 0 ) or ( ielas == 1) or ( ielas == 2);
  }
};
