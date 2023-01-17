
// This is the command sequence that rotates the ST7796S driver coordinate frame
//设置旋转方向

  rotation = m % 3; // Limit the range of values to 0-7

  writecommand(TFT_MADCTL);
  switch (rotation) {
    case 0:
      writedata((1<<3)|(1<<6));
      _width  = _init_width;
      _height = _init_height;
      break;
    case 1:
      writedata((1<<3)|(1<<5));
      _width  = _init_height;
      _height = _init_width;
      break;
    case 2:
      writedata((1<<3)|(1<<7));
      _width  = _init_width;
      _height = _init_height;
      break;
    case 3:
      writedata((1<<3)|(1<<7)|(1<<6)|(1<<5));
      _width  = _init_height;
      _height = _init_width;
      break;
  }

