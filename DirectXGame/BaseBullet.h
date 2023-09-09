﻿#pragma once
#include "Sprite.h"
#include "MyMath.h"
#include <memory>

/// <summary>
/// 弾のベースクラス
/// </summary>
class BaseBullet {
public: // メンバ変数
	virtual void Initialize(uint32_t texture, const Vector2& pos, Vector2 velosity);

	/// <summary>
	/// 更新処理
	/// </summary>
	virtual void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw();

	/// <summary>
	/// 衝突処理
	/// </summary>
	virtual void OnCollision();

	void SetSize(Vector2 size);

	Vector2 GetSize();
	void SetSceneVelo(Vector2 velo) { sceneVelo = velo; }

protected: // メンバ変数
	// スプライト
	std::unique_ptr<Sprite> sprite_;
	// テクスチャ
	uint32_t texture_;

	// 位置
	Vector2 pos_;

	// 速度
	Vector2 direction_;
	Vector2 sceneVelo;
	// 弾の速さ
	float bulletSpeed = 20.0f;
	// 弾の有効フラグ
	bool isDead_;

	// 半径サイズ
	float radius_;

	float bulletSpeed_;

	int animationTimer = 0;
	int animationNumber = 0;
	int animationScene = 5;
	int oneTime = 20;
	bool isAnimation = false;

public:
	/// <summary>
	/// 座標のSetter
	/// </summary>
	/// <param name="pos"></param>
	void SetPosition(Vector2& pos) { pos_ = pos; }


	/// <summary>
	/// 半径のSetter
	/// </summary>
	/// <param name="rad"></param>
	void SetRadius(float rad) { radius_ = rad; }


	/// <summary>
	/// フラグの設定
	/// </summary>
	/// <param name="dead"></param>
	void SetIsDead(bool dead) { isDead_ = dead; }

	void SetBulletSpeed(float speed) { bulletSpeed = speed; }

public: // ゲッター関数	
	/// <summary>
	/// 座標のGetter
	/// </summary>
	/// <returns></returns>
	Vector2 GetPosition() { return pos_; }

	/// <summary>
	/// 半径のGetter
	/// </summary>
	/// <returns></returns>
	float GetRadius() { return radius_; }

	/// <summary>
	/// フラグの取得
	/// </summary>
	/// <returns></returns>
	bool GetIsDead() { return isDead_; } 

	/// <summary>
	/// 弾の速さの取得
	/// </summary>
	/// <returns></returns>
	float GetBulletSpeed() { return bulletSpeed; }
};
