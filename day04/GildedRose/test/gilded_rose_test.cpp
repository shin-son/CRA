#include "gilded_rose.h"

#include "gmock/gmock.h"

using std::string;
using std::vector;

TEST(GildedRoseTest, noname) {
  vector<Item> items;
  items.emplace_back("noname", 0, 1);

  GildedRose app(items);
  app.updateQuality();

  EXPECT_EQ(-1, items[0].sellIn);
  EXPECT_EQ(0, items[0].quality);
}

TEST(GildedRoseTest, noname2) {
  vector<Item> items;
  items.emplace_back("noname2", -1, 30);

  GildedRose app(items);
  app.updateQuality();

  EXPECT_EQ(-2, items[0].sellIn);
  EXPECT_EQ(28, items[0].quality);
}

TEST(GildedRoseTest, Sulfras) {
  vector<Item> items;
  items.emplace_back("Sulfuras, Hand of Ragnaros", 0, 80);

  GildedRose app(items);
  app.updateQuality();

  EXPECT_EQ(0, items[0].sellIn);
  EXPECT_EQ(80, items[0].quality);
}

TEST(GildedRoseTest, Aged_Brie) {
  vector<Item> items;
  items.emplace_back("Aged Brie", 10, 40);

  GildedRose app(items);
  app.updateQuality();

  EXPECT_EQ(9, items[0].sellIn);
  EXPECT_EQ(41, items[0].quality);
}

TEST(GildedRoseTest, Aged_Brie2) {
  vector<Item> items;
  items.emplace_back("Aged Brie", -1, 40);

  GildedRose app(items);
  app.updateQuality();

  EXPECT_EQ(-2, items[0].sellIn);
  EXPECT_EQ(42, items[0].quality);
}

TEST(GildedRoseTest, Backstage) {
  vector<Item> items;
  items.emplace_back("Backstage passes to a TAFKAL80ETC concert", 10, 10);

  GildedRose app(items);
  app.updateQuality();

  EXPECT_EQ(9, items[0].sellIn);
  EXPECT_EQ(12, items[0].quality);
}

TEST(GildedRoseTest, Backstage2) {
  vector<Item> items;
  items.emplace_back("Backstage passes to a TAFKAL80ETC concert", 5, 10);

  GildedRose app(items);
  app.updateQuality();

  EXPECT_EQ(4, items[0].sellIn);
  EXPECT_EQ(13, items[0].quality);
}

TEST(GildedRoseTest, Backstage3) {
  vector<Item> items;
  items.emplace_back("Backstage passes to a TAFKAL80ETC concert", 0, 10);

  GildedRose app(items);
  app.updateQuality();

  EXPECT_EQ(-1, items[0].sellIn);
  EXPECT_EQ(0, items[0].quality);
}