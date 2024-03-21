using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RandomImageDisplay : MonoBehaviour
{
    public GameObject[] images; // �ǳڿ� ǥ���� �̹������� �迭

    void Start()
    {
        // �ǳڿ� �ִ� �̹������� ��Ȱ��ȭ
        foreach (GameObject image in images)
        {
            image.SetActive(false);
        }

        // �����ϰ� �̹����� �����Ͽ� Ȱ��ȭ
        int randomIndex = Random.Range(0, images.Length);
        images[randomIndex].SetActive(true);
    }
}