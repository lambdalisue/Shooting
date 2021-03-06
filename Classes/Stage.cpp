﻿//Stage.hというヘッダーファイルを読む
#include "Stage.h"

//名前空間cocos2dを使うという宣言
USING_NS_CC;

//Stageクラスのコンストラクタ
//_tiledMap(nullptr)「Stageクラスのpirvate変数_tiledMapに無を代入する」の意
Stage::Stage()
	: _tiledMap(nullptr)
{
}
//Stageクラスのデストラクタ
Stage::~Stage()
{
	CC_SAFE_RELEASE_NULL(_tiledMap);
}
//bool型のStage::init()関数を宣言

Enemy* Stage::popZako()
{
	float zakoY = RandomHelper::random_real<float>(80, 400);
	//Enemyクラスのポインタ変数enemyを作る
	Enemy *zakoenemy = ZakoEnemy::create();
	//enemyをX540,Y240の位置にセットする
	zakoenemy->setPosition(Vec2(540, zakoY));
	//取得したenemyのテクスチャに対して設定を与えている
	zakoenemy->getTexture()->setAliasTexParameters();
	//enemyの表示サイズを2倍にする
	zakoenemy->setScale(2.0f);
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("pop_se.wav");

	//戻り値にzakoenemyを返す
	return zakoenemy;
}
Enemy* Stage::popRare()
{
	float rareY = RandomHelper::random_real<float>(80, 400);
	//Enemyクラスのポインタ変数enemyを作る
	Enemy *rareenemy = RareEnemy::create();
	//enemyをX540,Y240の位置にセットする
	rareenemy->setPosition(Vec2(540, rareY));
	//取得したenemyのテクスチャに対して設定を与えている
	rareenemy->getTexture()->setAliasTexParameters();
	//enemyの表示サイズを2倍にする
	rareenemy->setScale(1.0f);
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("pop_se.wav");

	//戻り値にrereenemyを返す
	return rareenemy;

}

bool Stage::init()
{
	//int型の変数x,yを宣言、初期化
	int x = 0;
	int y = 0;

	//もしLayerが初期化されていなかったら返り値にfalseを返す
	if (!Layer::init())
	{
		return false;
	}
	//TMXTiledMapのポインタ変数mapにTMXTiledMap::create("test_map.tmx")を代入
	//test_map.tmxを読む
	auto map = TMXTiledMap::create("test_map.tmx");
	//TMXTiledMapのポインタ変数backgroundにmapのレイヤーbackgroundを代入
	// Tiledで設定したレイヤーの名前を渡す
	TMXLayer* background = map->getLayer("background");
	//TMXTiledMapのポインタ変数yukaにmapのレイヤーyukaを代入
	TMXLayer* yuka = map->getLayer("yuka");
	
	//なんとなくはわかるけどよくわからない
	//ここでTiledで設定した値からマップチップを並べている？
	background->getTileAt(Vec2(x, y));
	background->getTileGIDAt(Vec2(x, y));
	yuka->getTileAt(Vec2(x, y));
	yuka->getTileGIDAt(Vec2(x, y));


	//Stageクラスの表示場所を指定
	this->setPosition(320, 240);
	//Stageクラスのサイズを倍に指定
	this->setScale(2.0f);
	//Stageクラスの子にmapを加える（これで画像を描画だっけ）
	this->addChild(map);
	//StageクラスのTiledMapにmapを指定　おまじないかな
	this->setTiledMap(map);

	//Stageクラスを毎フレーム更新する
	this->scheduleUpdate();

	//返り値にtrueを返す
	return true;

}
//毎フレーム更新する
void Stage::update(float dt)
{

}