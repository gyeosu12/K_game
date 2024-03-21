using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RandomImageDisplay : MonoBehaviour
{
    public GameObject[] images; // 판넬에 표시할 이미지들의 배열

    void Start()
    {
        // 판넬에 있는 이미지들을 비활성화
        foreach (GameObject image in images)
        {
            image.SetActive(false);
        }

        // 랜덤하게 이미지를 선택하여 활성화
        int randomIndex = Random.Range(0, images.Length);
        images[randomIndex].SetActive(true);
    }
}