Invalid RATE. Use 1000..600000.")));
      }
  };

  // Read from Serial (USB)
  static String line1;
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n' || c == '\r') { if (line1.length()) { handleLine(line1); line1 = ""; } }
    else if (isPrintable(c)) { line1 += c; if (line1.length() > 80) line1.remove(0, 10); }
  }

  // Read from Bluetooth serial
#if USE_SOFTWARE_SERIAL
  static String line2;
  while (bt.available()) {
    char c = bt.read();
    if (c == '\n' || c == '\r') { if (line2.length()) { handleLine(line2); line2 = ""; } }
    else if (isPrintable(c)) { line2 += c; if (line2.length() > 80) line2.remove(0, 10); }
  }
#endif
}
