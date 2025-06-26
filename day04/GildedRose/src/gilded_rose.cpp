#include "gilded_rose.h"

using std::string;
using std::vector;

namespace {
const char* SULFURAS = "Sulfuras, Hand of Ragnaros";
const char* AGED_BRIE = "Aged Brie";
const char* BACKSTAGE_PASS = "Backstage passes to a TAFKAL80ETC concert";
}  // namespace

GildedRose::GildedRose(vector<Item>& items) : items(items) {}

void GildedRose::updateQuality() {
  for (int i = 0; i < items.size(); i++) {
    auto& item = items.at(i);
    if (item.name == AGED_BRIE) {
      if (item.quality < 50) {
        item.quality = item.quality + 1;
      }
    } else if (item.name == BACKSTAGE_PASS) {
      if (item.quality < 50) {
        item.quality = item.quality + 1;

        if (item.sellIn < 11) {
          if (item.quality < 50) {
            item.quality = item.quality + 1;
          }
        }

        if (item.sellIn < 6) {
          if (item.quality < 50) {
            item.quality = item.quality + 1;
          }
        }
      }
    } else if (item.name != SULFURAS) {
      if (item.quality > 0) {
        item.quality = item.quality - 1;
      }
    }

    if (item.name != SULFURAS) {
      item.sellIn = item.sellIn - 1;
    }

    if (item.name == AGED_BRIE) {
      if (item.sellIn < 0) {
        if (item.quality < 50) {
          item.quality = item.quality + 1;
        }
      }
    } else if (item.name == BACKSTAGE_PASS) {
      if (item.sellIn < 0) {
        item.quality = item.quality - item.quality;
      }
    } else if (item.name != SULFURAS) {
      if (item.sellIn < 0) {
        if (item.quality > 0) {
          item.quality = item.quality - 1;
        }
      }
    }
  }
}